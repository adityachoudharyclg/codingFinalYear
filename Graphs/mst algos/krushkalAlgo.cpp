#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
class Node {
   public:
    int src, dest, weight;
    Node(int src, int dest, int weight) {
        this->src = src;
        this->dest = dest;
        this->weight = weight;
    }
};
bool compare(Node a, Node b) {
    return a.weight < b.weight;
}
int set_find(int* arr, int x) {
    if (arr[x] < 0) {
        return x;
    }
    return set_find(arr, arr[x]);
}
void set_union(int* arr, int root1, int root2) {
    if (root1 == root2) {
        return;
    }
    if (arr[root1] < arr[root2]) {
        arr[root1] = root2;
    } else if (arr[root1] == arr[root2]) {
        arr[root1] -= 1;
        arr[root2] = root1;
    } else {
        arr[root2] = root1;
    }
}
void krushkal(vector<Node> g, int V) {
    sort(g.begin(), g.end(), compare);
    
    int cnt = 0;
    vector<Node> res;
    int* cycleDetect = new int[V];
    for (int i = 0; i < V; i++) {
        cycleDetect[i] = -1;
    }

    for (int i = 0; i < g.size() && cnt < V - 1; i++) {
        Node curNode = g[i];
        int root1 = set_find(cycleDetect, curNode.src);
        int root2 = set_find(cycleDetect, curNode.dest);
        if (root1 != root2) {
            set_union(cycleDetect, root1, root2);
            res.push_back(Node(min(curNode.src, curNode.dest), max(curNode.src, curNode.dest), curNode.weight));
            cnt++;
        }
    }

    // display edges
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].src << " " << res[i].dest << " " << res[i].weight << endl;
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<Node> g;
        while (E--) {
            int src, dest, weight;
            cin >> src >> dest >> weight;
            g.push_back(Node(src, dest, weight));
        }
        krushkal(g, V);
    }
    return 0;
}
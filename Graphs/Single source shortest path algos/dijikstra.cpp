#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
class Node {
   public:
    int vertex;
    int weight;
    Node(int vertex, int weight) {
        this->vertex = vertex;
        this->weight = weight;
    }
};

class myCompare {
   public:
    bool operator()(Node a, Node b) {
        return a.weight > b.weight;
    }
};

void dijikstra(vector<Node> g[], int V, int src) {
    // Initialisation
    bool* visited = new bool[V]();
    int* parent = new int[V];
    int* dist = new int[V];
    for (int i = 0; i < V; i++) {
        parent[i] = -1;
        dist[i] = INT_MAX;
    }

    // for source
    visited[src] = true;
    dist[src] = 0;

    // main task
    priority_queue<Node, vector<Node>, myCompare> pq;
    Node srcNode(src, 0);
    pq.push(srcNode);
    while (!pq.empty()) {
        Node top = pq.top();
        pq.pop();
        visited[top.vertex] = true;

        // Check condition for useless nodes in pq
        if (dist[top.vertex] < top.weight)
            continue;

        // Processing adjacent vertices
        for (int i = 0; i < g[top.vertex].size(); i++) {
            Node temp = g[top.vertex][i];
            if (!visited[temp.vertex]) {
                // Relaxation step
                int newDist = dist[top.vertex] + temp.weight;
                if (newDist < dist[temp.vertex]) {
                    parent[temp.vertex] = top.vertex;
                    dist[temp.vertex] = newDist;
                }
                Node newNode(temp.vertex, dist[temp.vertex]);
                pq.push(newNode);
            }
        }
    }

    // Printing results
    for (int i = 0; i < V; i++) {
        printf("%4d %4d %4d\n", i, dist[i], parent[i]);
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
        vector<Node>* g = new vector<Node>[V];
        while (E--) {
            int x, y, w;
            cin >> x >> y >> w;
            Node temp(y, w);
            g[x].push_back(temp);
            Node temp2(x, w);
            g[y].push_back(temp2);
        }
        dijikstra(g, V, 0);
    }
    return 0;
}
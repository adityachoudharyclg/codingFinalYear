#include <bits/stdc++.h>
using namespace std;
class Node {
   public:
    int dist, vertex;
    Node(int a, int b) {
        vertex = a;
        dist = b;
    }
};
class myCompare {
   public:
    bool operator()(Node a, Node b) {
        return a.dist > b.dist;
    }
};
int spanningTree(int V, int E, vector<vector<int>>& graph) {
    // code here
    bool* visited = new bool[V];
    int* dist = new int[V];
    int* parent = new int[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
    parent[0] = 0;
    dist[0] = 0;
    priority_queue<Node, vector<Node>, myCompare> pq;
    pq.push(Node(0, 0));
    int cnt = 0, mst_res = 0;
    while (cnt < V - 1 && !pq.empty()) {
        Node top = pq.top();
        pq.pop();
        cnt++;
        visited[top.vertex] = true;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && graph[top.vertex][i] != INT_MAX) {
                if (dist[i] > graph[top.vertex][i]) {
                    parent[i] = top.vertex;
                    dist[i] = graph[top.vertex][i];
                }
                pq.push(Node (i,dist[i]));
            }
        }
    }
    for (int i = 0; i < V; i++) {
        mst_res += dist[i];
        cout<<min(i,parent[i])<<" "<<max(i,parent[i])<<" "<<dist[i]<<endl;
    }
    // cout<<endl;
    return mst_res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> graph(V, vector<int>(V, INT_MAX));
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        spanningTree(V, E, graph) ;
    }
    return 0;
}
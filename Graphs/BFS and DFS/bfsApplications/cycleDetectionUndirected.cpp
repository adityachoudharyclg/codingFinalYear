#include <bits/stdc++.h>
using namespace std;
bool helper(vector<int> g[], bool* visited, int* parent, int V, int start) {
    // cout << start << " ";
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int front = q.front();
        visited[front] = true;
        q.pop();
        for (int i = 0; i < g[front].size(); i++) {
            int vertex = g[front][i];
            if (!visited[vertex]) {
                parent[vertex] = front;
                q.push(vertex);
            } else if (parent[front] != vertex) {
                return true;
            }
        }
    }
    return false;
}
bool isCyclic(vector<int> g[], int V) {
    // Your code here
    bool* visited = new bool[V]();
    int* parent = new int[V]();
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        parent[i] = -1;
    }
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (helper(g, visited, parent, V, i)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        // array of vectors to represent graph
        vector<int> adj[V];

        int u, v;
        for (int i = 0; i < E; i++) {
            cin >> u >> v;

            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V) << endl;
    }
}
// } Driver Code Ends
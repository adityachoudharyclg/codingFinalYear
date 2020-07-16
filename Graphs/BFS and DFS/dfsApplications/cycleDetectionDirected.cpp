#include <bits/stdc++.h>
using namespace std;
bool isCyclic(vector<int> g[], bool* visited, bool* recStack, int V, int src) {
    visited[src] = true;
    recStack[src] = true;
    for (int i = 0; i < g[src].size(); i++) {
        int vertex = g[src][i];
        if (!visited[vertex]) {
            if (isCyclic(g, visited, recStack, V, vertex))
                return true;
        } else if (recStack[vertex]) {
            return true;
        }
    }
    recStack[src] = false;
    return false;
}

bool isCyclic(int V, vector<int> g[]) {
    // Your code here
    bool* visited = new bool[V]();
    bool* recStack = new bool[V]();

    // Call for all vertices
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclic(g, visited, recStack, V, i))
                return true;
        }
    }

    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;

    while (t--) {
        int v, e;
        cin >> v >> e;

        vector<int> adj[v];

        for (int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        cout << isCyclic(v, adj) << endl;
    }

    return 0;
}
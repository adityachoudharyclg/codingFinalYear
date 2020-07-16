#include <bits/stdc++.h>
using namespace std;
void dfsStack(vector<int> g[], bool* visited, int V, int src, stack<int>& S) {
    visited[src] = true;
    for (int i = 0; i < g[src].size(); i++) {
        int vertex = g[src][i];
        if (!visited[vertex]) {
            visited[vertex] = true;
            dfsStack(g, visited, V, vertex, S);
        }
    }
    S.push(src);
}

void transpose(vector<int> g[], int V) {
    vector<int> temp[V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            int vertex = g[i][j];
            temp[vertex].push_back(i);
        }
    }
    for (int i = 0; i < V; i++) {
        g[i] = temp[i];
    }
}

int kosaraju(int V, vector<int> g[]) {
    // Your code here
    stack<int> stk;
    bool* visited = new bool[V]();
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfsStack(g, visited, V, i, stk);
        }
    }

    // transpose
    transpose(g, V);

    // Calculating components;
    delete[] visited;
    visited = new bool[V]();
    int cnt = 0;
    stack<int> junk;
    while (!stk.empty()) {
        int vertex = stk.top();
        if (!visited[vertex]) {
            dfsStack(g, visited, V, vertex, junk);
            cnt++;
        }
        stk.pop();
    }
    return cnt;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int m, n;
        vector<int> adj[a];
        for (int i = 0; i < b; i++) {
            cin >> m >> n;
            adj[m].push_back(n);
        }
        cout << kosaraju(a, adj) << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int countPossiblePaths(vector<int> g[], bool* visited, int V, int src, int dest) {
    if (src == dest) {
        visited[src] = false;
        return 1;
    }
    int cnt = 0;
    visited[src] = true;
    for (int i = 0; i < g[src].size(); i++) {
        int vertex = g[src][i];
        if (!visited[vertex]) {
            cnt += countPossiblePaths(g, visited, V, vertex, dest);
            visited[i] = false;
        }
    }
    return cnt;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int>* g = new vector<int>[V];
        bool* visited = new bool[V];
        while (E--) {
            int src, dest;
            cin >> src >> dest;
            g[src].push_back(dest);
        }
        int start, end;
        cin >> start >> end;
        cout << countPossiblePaths(g, visited, V, start, end);
    }
    return 0;
}
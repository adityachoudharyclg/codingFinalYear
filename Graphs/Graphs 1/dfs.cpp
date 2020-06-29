#include <bits/stdc++.h>
using namespace std;
void dfs(int graph[][100], bool visited[100], int start, int n) {
    cout << start << "->";
    visited[start]=true;
    for (int i = 0; i <= n; i++) {
        if (!visited[i] && graph[start][i]) {
            dfs(graph, visited, i, n);
        }
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m;
    cin >> m;
    pair<int, int> edges[m];
    int graph[100][100], maxi;
    // undireccted graph
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
        graph[edges[i].first][edges[i].second] = 1;
        graph[edges[i].second][edges[i].first] = 1;
        maxi = max(maxi, max(edges[i].first, edges[i].second));
    }
    bool visited[100];
    dfs(graph, visited, edges[0].first, maxi);
    cout<<endl;
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
void dfs(int** graph, int* visited, int V, int start) {
    if(visited[start]){
        return;
    }
    cout<<start<<" ";
    visited[start]=1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && graph[start][i]) {
            cout<<"Hello"<<endl;
            dfs(graph, visited, V, i);
        }
    }
}
void dfs(int** graph, int V) {
    int* visited = new int[V]();
    for (int i = 0; i < V; i++) {
        if(!visited[i])
            dfs(graph, visited, V, i);
        cout<<endl;
    }
    cout << endl;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        int** graph = new int*[V];
        for (int i = 0; i < V; i++) {
            graph[i] = new int[V]();
        }
        while (E--) {
            int x, y;
            cin >> x >> y;
            graph[x][y] = 1;
        }
        dfs(graph, V);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void bfs(int** mat, bool* visited, int V, int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int front = q.front();
        cout << front << " ";
        q.pop();
        for (int i = 0; i < V; i++) {
            if (!visited[i] && mat[front][i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void bfs(int** mat, int V) {
    bool* visited = new bool[V]();
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            bfs(mat, visited, V, i);
        }
    }
    delete [] visited;
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
        int** mat = new int*[V];
        for (int i = 0; i < V; i++) {
            mat[i] = new int[V];
        }
        for (int i = 0; i < E; i++) {
            int x, y;
            cin>>x>>y;
            mat[x][y] = 1;
            mat[y][x] = 1;
        }
        bfs(mat, V);
        for (int i = 0; i < V; i++) {
            delete [] mat[i];
        }
        delete [] mat;
    }
    return 0;
}
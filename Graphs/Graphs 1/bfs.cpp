#include <bits/stdc++.h>

#include <iostream>
using namespace std;

void printBFS(int **edges, int V, int sv) {
    queue<int> pend;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    pend.push(sv);
    visited[sv] = true;
    while (!pend.empty()) {
        int topper = pend.front();
        pend.pop();
        cout << topper << " ";
        for (int j = 0; j < V; j++) {
            if (j == topper) {
                continue;
            }

            if (edges[topper][j] == 1 && !visited[j]) {
                pend.push(j);
                visited[j] = true;
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int V, E;
    cin >> V >> E;
    int **edge = new int *[V];
    for (int i = 0; i < V; i++) {
        edge[i] = new int[V];
        for (int k = 0; k < V; k++) {
            edge[i][k] = 0;
        }
    }

    for (int p = 0; p < E; p++) {
        int f, s;
        cin >> f >> s;
        edge[f][s] = 1;
        edge[s][f] = 1;
    }

    printBFS(edge, V, 0);

    return 0;
}

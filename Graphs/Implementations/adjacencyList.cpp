#include <bits/stdc++.h>
using namespace std;
class Graph {
    int V;
    unordered_map<int, vector<int>> adjList;

   public:
    Graph(int v = 0) {
        V = v;
    }

    void addEdge(int source, int dest) {
        adjList[source].push_back(dest);
        adjList[dest].push_back(source);
    }

    void printAdjList() {
        for (int i = 0; i < V; i++) {
            adjList[i];
            if (adjList[i].size() == 0) {
                cout << i;
            } else {
                cout << i << "-> ";
            }
            for (int j = 0; j < adjList[i].size(); j++) {
                if ((j + 1) != adjList[i].size())
                    cout << adjList[i][j] << "-> ";
                else
                    cout << adjList[i][j];
            }
            cout << endl;
        }
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        Graph g(V);
        while (E--) {
            int x, y;
            cin >> x >> y;
            g.addEdge(x, y);
        }
        g.printAdjList();
    }
    return 0;
}
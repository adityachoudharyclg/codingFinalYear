#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
class Node {
   public:
    int src, dest, weight;
    Node(int x, int y, int w) {
        src = x;
        dest = y;
        weight = w;
    }
};
bool bellmanFord(vector<Node> g, int V, int src) {
    int* dist = new int[V]();
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    // Realaxing all edges
    for (int i = 0; i <= V - 1; i++) {
        for (int j = 0; j < g.size(); j++) {
            // Relaxation step
            if (dist[g[j].dest] > dist[g[j].src] + g[j].weight) {
                dist[g[j].dest] = dist[g[j].src] + g[j].weight;
            }
        }
    }
    // Checking for negative cycle
    for (int i = 0; i <= V - 1; i++) {
        for (int j = 0; j < g.size(); j++) {
            // Relaxation step
            if (dist[g[j].dest] > dist[g[j].src] + g[j].weight) {
                return true;
            }
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
        int V, E;
        cin >> V >> E;
        vector<Node> g;
        while (E--) {
            int x, y, w;
            cin >> x >> y >> w;
            g.push_back(Node(x, y, w));
        }
        cout << bellmanFord(g, V, 0) << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
void allTopologicalSortUtil(vector<int> g[], int V, bool* visited, int* indegree, vector<int>& res) {
    bool flag = false;
    
    for (int i = 0; i < V; i++) {
        // processing 0 indegree vertices
        if (indegree[i] == 0 && !visited[i]) {
            // reduce indegree of adjacent vertices
            for (int j = 0; j < g[i].size(); j++) {
                int vertex = g[i][j];
                indegree[vertex]--;
            }

            // mark visited, include in result
            visited[i] = true;
            res.push_back(i);
            allTopologicalSortUtil(g, V, visited, indegree, res);

            // Reset visited,res and indegree
            visited[i] = false;
            res.erase(res.end() - 1);
            for (int j = 0; j < g[i].size(); j++) {
                int vertex = g[i][j];
                indegree[vertex]++;
            }

            flag = true;
        }
    }

    //  We reach here if all vertices are visited.
    //  So we print the solution here
    if (!flag) {
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}
void allTopologicalSort(vector<int> g[], int V, int* indegree) {
    vector<int> res;
    bool* visited = new bool[V]();
    allTopologicalSortUtil(g, V, visited, indegree, res);
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
        int* indegree = new int[V]();
        while (E--) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            indegree[y]++;
        }
        allTopologicalSort(g, V, indegree);
    }
    return 0;
}
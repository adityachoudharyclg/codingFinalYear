// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool check(int V, vector<int>& res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

bool compare(vector<int> a, vector<int> b) {
    return a.size() > b.size();
}

vector<int> helper(vector<int> g[], bool* visited, int* parent, int V, int start) {
    visited[start] = true;
    vector<int> ans;
    for (int i = 0; i < g[start].size(); i++) {
        int vertex = g[start][i];
        if (!visited[vertex]) {
            parent[vertex] = start;
            vector<int> temp = helper(g, visited, parent, V, vertex);
            ans.insert(ans.begin(), temp.begin(), temp.end());
        }
    }
    ans.insert(ans.begin(), start);
    return ans;
}

class myComparision {
   public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    }
};

vector<int> topoSort(int V, vector<int> adj[]) {
    bool* visited = new bool[V]();
    int* parent = new int[V];
    for (int i = 0; i < V; i++) {
        parent[i] = -1;
    }
    vector<int> res;
    priority_queue<pair<int, int>, vector<pair<int, int>>, myComparision> pq;

    for (int i = 0; i < V; i++) {
        pair<int, int> p;
        p.first = adj[i].size();
        p.second = i;
        pq.push(p);
    }

    while (!pq.empty()) {
        pair<int, int> temp = pq.top();
        int vertex = temp.second;
        if (!visited[vertex]) {
            // cout<<vertex<<endl;
            vector<int> temp = helper(adj, visited, parent, V, vertex);
            res.insert(res.begin(), temp.begin(), temp.end());
        }
        pq.pop();
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector<int> res = topoSort(N, adj);
        cout << check(N, res, adj) << endl;
    }
}

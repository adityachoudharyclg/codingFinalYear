#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define ppi pair<int, int>
#define pq_min(T) priority_queue<T, vector<T>,greater<T>>
#define ump unordered_map<int, int>
using namespace std;
void solve(int arr[], int n, int k) {
    pq_min(ppi) pq;
    vector<int> res;
    ump hashmap;

    for (int i = 0; i < n; i++) {
        hashmap[arr[i]]++;
    }

    for (ump::iterator it = hashmap.begin(); it != hashmap.end(); it++) {
        pq.push(make_pair(it->second, it->first));
        if (pq.size() > k) {
            pq.pop();
        }
    }

    while (!pq.empty()) {
        res.push_back(pq.top().second);
        pq.pop();
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int k;
        cin >> k;
        solve(arr, n, k);
    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pq_min(T) priority_queue<T, vector<T>, greater<T>>
using namespace std;
void solve(int arr[], int n, int k) {
    pq_min(int) pq;
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    vector<int> res;
    while (!pq.empty()) {
        res.push_back(pq.top());
        pq.pop();
    }
    for (int i = res.size() - 1; i >= 0; i--) {
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
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(arr, n, k);
    }
    return 0;
}
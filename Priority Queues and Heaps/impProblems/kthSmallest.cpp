#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pq_int(T) priority_queue<T, vector<T>>
using namespace std;
int solve(int arr[], int n, int k) {
    pq_int(int) pq;
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    return pq.top();
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
        cout << solve(arr, n, k) << endl;
    }
    return 0;
}
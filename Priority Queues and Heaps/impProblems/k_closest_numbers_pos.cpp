#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define ppi pair<int, int>
#define pq_max(T) priority_queue<T, vector<T>>
using namespace std;
void solve(int input[], int n, int k, int x) {
    pq_max(ppi) pq;
    vector<int> arr(input, input + n);
    int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    for (int i = 0; i < n; i++) {
        if (i == pos) {
            continue;
        }
        pq.push(make_pair(abs(i - pos), arr[i]));
        if (pq.size() > k) {
            pq.pop();
        }
    }

    while (!pq.empty()) {
        cout << pq.top().second << " ";
        pq.pop();
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
        int k, x;
        cin >> k >> x;
        solve(arr, n, k, x);
    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
void solve(int arr[], int n) {
    stack<pair<int, int>> stk;
    vector<int> res;
    for (int i = n-1; i >=0 ; i--) {
        while (!stk.empty() && arr[i] <= stk.top().second) {
            stk.pop();
        }
        if (stk.empty()) {
            res.push_back(-1);
        } else {
            res.push_back(stk.top().first);
        }
        stk.push(make_pair(i, arr[i]));
    }
    reverse(res.begin(),res.end());
    for (int i = 0; i < n; i++) {
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
        solve(arr, n);
    }
    return 0;
}
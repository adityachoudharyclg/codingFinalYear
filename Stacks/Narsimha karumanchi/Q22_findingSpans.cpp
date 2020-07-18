#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
void solve(int arr[], int n) {
    stack<int> stk;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        while (!stk.empty() && arr[i] >= arr[stk.top()]) {
            stk.pop();
        }
        if (stk.empty()) {
            res.push_back(i + 1);
        } else {
            res.push_back(i - stk.top());
        }
        stk.push(i);
    }
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
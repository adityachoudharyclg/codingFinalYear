#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int arr[], int n) {
    stack<int> stk;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (stk.empty() || arr[i] > arr[stk.top()]) {
            stk.push(i);
        } else {
            int curr = stk.top();
            stk.pop();
            int width = stk.empty() ? i : i - stk.top() - 1;
            res = max(res, arr[curr] * width);
            i--;
        }
    }
    while (!stk.empty()) {
        int curr = stk.top();
        stk.pop();
        int width = stk.empty() ? n : n - stk.top() - 1;
        res = max(res, arr[curr] * width);
    }
    return res;
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
        cout << solve(arr, n) << endl;
    }
    return 0;
}
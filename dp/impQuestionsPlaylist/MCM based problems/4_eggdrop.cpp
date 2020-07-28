#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int helper(int n, int k, int** dp) {
    // Base condition
    // cout << n << " " << k << endl;
    if (n == 0 || n == 1) {
        dp[n][k] = n;
        return n;
    }
    if (k == 1) {
        dp[n][k] = n;
        return n;
    }
    // General condition
    int cnt = INT_MAX;
    // cout << n << k << endl;
    if (dp[n][k] != -1) {
        return dp[n][k];
    }
    for (int i = 1; i <= n; i++) {
        int l = dp[i - 1][k - 1] != -1 ? dp[i - 1][k - 1] : helper(i - 1, k - 1, dp);
        int r = dp[n - i][k] != -1 ? dp[n - i][k] : helper(n - i, k, dp);
        // cout << n << " " << k << " " << l << " " << r << " " << endl;
        cnt = min(max(l, r) + 1, cnt);
    }
    dp[n][k] = cnt;
    return cnt;
}
int solve(int n, int k) {
    int** dp = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = new int[k + 1];
        for (int j = 0; j <= k; j++) {
            dp[i][j] = -1;
        }
    }
    return helper(n, k, dp);
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}
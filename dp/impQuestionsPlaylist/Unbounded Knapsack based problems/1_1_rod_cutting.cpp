#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int arr[], int n) {
    // 2d simple solution
    // int dp[n + 1][n + 1];
    // memset(dp, 0, sizeof(dp));
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         if (j >= i) {
    //             dp[i][j] = max(dp[i - 1][j], dp[i][j - (i)] + arr[i - 1]);
    //         } else {
    //             dp[i][j] = dp[i - 1][j];
    //         }
    //     }
    // }
    // return dp[n][n];

    // 1d solution
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        int max_val = INT_MIN;
        for (int j = 0; j < i; j++) {
            max_val = max(max_val, arr[j] + dp[i - j - 1]);
        }
        dp[i] = max_val;
    }
    return dp[n];
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
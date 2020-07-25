#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int memoized_soln(int values[], int weights[], int n, int w, int** dp) {
    if (n == 0 || w == 0) {
        return 0;
    }
    if (dp[n][w] != -1) {
        return dp[n][w];
    }
    int res1 = 0;
    int res2 = 0;
    if (w >= weights[n - 1])
        res1 = memoized_soln(values, weights, n, w - weights[n - 1], dp) + values[n - 1];
    res2 = memoized_soln(values, weights, n - 1, w, dp);
    dp[n][w] = max(res1, res2);
    return max(res1, res2);
}
int solve(int values[], int weights[], int n, int w) {
    // Code for memoized soln
    // int** dp = new int*[n + 1];
    // for (int i = 0; i <= n; i++) {
    //     dp[i] = new int[w + 1];
    //     for (int j = 0; j <= w; j++) {
    //         dp[i][j] = -1;
    //     }
    // }
    // return memoized_soln(values, weights, n, w, dp);

    // Code for tabulation
    int dp[n + 1][w + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (j >= weights[i - 1]) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n, w;
        cin >> n >> w;
        int weights[n], values[n];
        for (int i = 0; i < n; i++) {
            cin >> values[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> weights[i];
        }
        cout << solve(values, weights, n, w) << endl;
    }
    return 0;
}
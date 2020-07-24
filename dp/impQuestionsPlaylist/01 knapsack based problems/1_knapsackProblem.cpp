#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int values[], int weights[], int N, int W) {
    int dp[N + 1][W + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= W; j++) {
            if (weights[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]]);
            }
        }
    }
    return dp[N][W];
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int N, W;
        cin >> N >> W;
        int weights[N], values[N];
        for (int i = 0; i < N; i++) {
            cin >> values[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> weights[i];
        }
        cout << solve(values, weights, N, W) << endl;
    }
    return 0;
}
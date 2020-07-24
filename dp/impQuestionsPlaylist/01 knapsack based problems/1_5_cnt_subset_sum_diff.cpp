#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int cntSubsetSum(int arr[], int n, int target) {
    // This logic counts only distinct subsets possible
    int dp[n + 1][target + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (j < arr[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                if (arr[i - 1] != 0)
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][target];
}
int solve(int arr[], int n, int diff) {
    int tot = accumulate(arr, arr + n, 0);
    return cntSubsetSum(arr, n, (tot + diff) / 2);
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
        int diff;
        cin >> diff;
        cout << solve(arr, n, diff) << endl;
    }
    return 0;
}
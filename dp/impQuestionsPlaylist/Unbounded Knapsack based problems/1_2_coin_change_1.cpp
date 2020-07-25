#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int arr[], int n, int target) {
    int dp[n + 1][target + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n + 1; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (j >= arr[i - 1]) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][target];
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
        int target;
        cin >> target;
        cout << solve(arr, n, target) << endl;
    }
    return 0;
}
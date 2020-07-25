#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int arr[], int n, int target) {
    int dp[n + 1][target + 1];
    for (int i = 0; i <= target; i++)
        dp[0][i] = INT_MAX - 1;
    for (int i = 1; i <= n; i++)
        dp[i][0] = 0;
    // Super imp initialisation of 2nd row
    for (int i = 1; i <= target; i++) {
        if (i % arr[0] == 0) {
            dp[1][i] = i / arr[0];
        } else {
            dp[1][i] = INT_MAX - 1;
        }
    }
    // General
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (j >= arr[i - 1]) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - arr[i - 1]] + 1);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][target] == INT_MAX - 1 ? -1 : dp[n][target];
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        int target;
        cin >> target;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(arr, n, target) << endl;
    }
    return 0;
}
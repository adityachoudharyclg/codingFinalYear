#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
bool subsetSumSolver(int arr[], int n, int target) {
    bool dp[n + 1][target + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (j < arr[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    return dp[n][target];
}
bool solve(int arr[], int n) {
    int sum = accumulate(arr, arr + n, 0);
    if (sum & 1) {
        return false;
    }
    return subsetSumSolver(arr, n, sum / 2);
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
        cout << (solve(arr, n) == true ? "YES" : "NO") << endl;
    }
    return 0;
}
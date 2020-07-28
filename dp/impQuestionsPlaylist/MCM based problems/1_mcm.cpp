#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int mcm(int arr[], int i, int j, int dp[][100]) {
    if ((j - i + 1) < 3)
        return 0;
    int res = INT_MAX;
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    for (int k = i + 1; k < j; k++) {
        int l = mcm(arr, i, k, dp);
        int r = mcm(arr, k, j, dp);
        // cout << "Res:" << i << " " << j << " " << l << " " << r << " " << arr[i] * arr[k] * arr[j] << endl;
        res = min(res, l + r + arr[i] * arr[k] * arr[j]);
    }
    dp[i][j] = res;
    return res;
}
int solve(int arr[], int n) {
    int dp[100][100];
    memset(dp, -1, sizeof(dp));
    return mcm(arr, 0, n - 1, dp);
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
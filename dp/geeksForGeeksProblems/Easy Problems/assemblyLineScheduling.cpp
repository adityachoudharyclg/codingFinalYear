#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int arr[][100], int n, pair<int, int> e, pair<int, int> x, int transitionTime[][100]) {
    int dp[2][n];
    dp[0][0] = arr[0][0] + e.first;
    dp[1][0] = arr[1][0] + e.second;
    cout << dp[0][0] << " " << dp[1][0] << endl;
    for (int i = 1; i < n; i++) {
        dp[0][i] = min(dp[0][i - 1] + arr[0][i], dp[1][i - 1] + arr[0][i] + transitionTime[1][i - 1]);
        dp[1][i] = min(dp[1][i - 1] + arr[1][i], dp[0][i - 1] + arr[1][i] + transitionTime[0][i - 1]);
        // cout << dp[0][i] << " " << dp[1][i] << " " << transitionTime[0][i - 1] << " " << transitionTime[1][i - 1] << endl;
    }
    return min(dp[0][n - 1] + x.first, dp[1][n - 1] + x.second);
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[2][100];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        pair<int, int> e, x;
        cin >> e.first >> e.second;
        cin >> x.first >> x.second;
        int transitionTime[2][100];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n - 1; j++) {
                cin >> transitionTime[i][j];
            }
        }
        cout << solve(arr, n, e, x, transitionTime);
    }
    return 0;
}
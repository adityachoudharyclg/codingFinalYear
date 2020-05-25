#include <bits/stdc++.h>
#define ll long long
#define m 1000000007
using namespace std;
int solve(int arr[], int n, int w) {
    int dp[n + 1][w + 1];
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= w; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            if (arr[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - arr[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= w; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[n][w];
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
        int capacity;
        cin >> capacity;
        cout << solve(arr, n, capacity) << endl;
    }
    return 0;
}
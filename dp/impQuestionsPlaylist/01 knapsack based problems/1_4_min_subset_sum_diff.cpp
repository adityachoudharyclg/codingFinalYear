#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int helper(int arr[], int n, int cur_sum, int tot_sum, int** dp) {
    if (n == 0) {
        return abs((tot_sum - cur_sum) - cur_sum);
    }
    dp[n][cur_sum] = dp[n][cur_sum] != -1 ? dp[n][cur_sum] : helper(arr, n - 1, cur_sum, tot_sum, dp);
    dp[n][cur_sum + arr[n - 1]] = dp[n][cur_sum + arr[n - 1]] != -1 ? dp[n][cur_sum + arr[n - 1]] : helper(arr, n - 1, cur_sum + arr[n - 1], tot_sum, dp);
    return min(dp[n][cur_sum], dp[n][cur_sum + arr[n - 1]]);
}
int solve(int arr[], int n) {
    // Memoized solution
    int** dp = new int*[n + 1];
    int tot_sum = accumulate(arr, arr + n, 0);
    for (int i = 0; i <= n; i++) {
        dp[i] = new int[tot_sum + 1];
        for (int j = 0; j <= tot_sum; j++) {
            dp[i][j] = -1;
        }
    }
    return helper(arr, n, 0, tot_sum, dp);
}
int solved_tabulation(int arr[], int n) {
    int tot_sum = accumulate(arr, arr + n, 0);
    // ith col denotes ele, jth col denotes cur sum.
    bool dp[n][tot_sum + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= tot_sum; j++) {
            if (dp[i - 1][j]) {
                dp[i][j] = true;
                dp[i][j + arr[i]] = true;
            }
        }
    }
    int res = INT_MAX;
    for (int j = 0; j <= tot_sum; j++) {
        if (dp[n - 1][j]) {
            res = min(res, abs((tot_sum - j) - j));
        }
    }
    return res;
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
        cout << solved_tabulation(arr, n) << endl;
    }
    return 0;
}
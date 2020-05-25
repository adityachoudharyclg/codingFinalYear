#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int arr[], int n) {
    int dp[n + 1];
    memset(dp,0,sizeof(dp));
    dp[0] = 0;
    dp[1] = arr[0];
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] > (dp[i - 2] + arr[i-1]) ? dp[i - 1] : dp[i - 2] + arr[i-1];
    }
    return dp[n];
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
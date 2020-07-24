#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int helper(int arr[], int n, int cs, int ts, int dp[][2001]) {
    if (n == 0) {
        return cs == ts;
    }
    if(dp[n][cs+1000]!=-1){
        return dp[n][cs+1000];
    }
    int add = helper(arr,n-1,cs+arr[n-1],ts,dp);
    int sub = helper(arr,n-1,cs-arr[n-1],ts,dp);
    dp[n][cs+1000]=add+sub;
    return dp[n][cs+1000];
}
int solve(int arr[], int n, int target) {
    // int tot = accumulate(arr, arr + n, 0);
    int dp[n + 1][2001];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 2000; j++) {
            dp[i][j] = -1;
        }
    }
    return helper(arr, n, 0, target, dp);
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
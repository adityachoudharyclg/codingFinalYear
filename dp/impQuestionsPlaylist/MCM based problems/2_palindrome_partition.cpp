#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int checkPalindrome(string arr, int start, int end) {
    for (int i = start, j = end; i < j; i++, j--) {
        if (arr[i] != arr[j])
            return false;
    }
    return true;
}
int pp(string arr, int i, int j, int** dp) {
    if ((j - i + 1) < 2)
        return 0;
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    if (checkPalindrome(arr, i, j))
        return 0;
    int res = INT_MAX;
    for (int k = i; k < j; k++) {
        int l = dp[i][k] != -1 ? dp[i][k] : pp(arr, i, k, dp);
        int r = dp[k + 1][j] != -1 ? dp[k + 1][j] : pp(arr, k + 1, j, dp);
        res = min(l + r + 1, res);
    }
    dp[i][j] = res;
    return res;
}
int solve(string arr, int n) {
    int** dp = new int*[n];
    for (int i = 0; i < n; i++) {
        dp[i] = new int[n];
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }
    return pp(arr, 0, n - 1, dp);
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        string arr;
        cin >> arr;
        cout << solve(arr, arr.size()) << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int lcs(string a, string b, int m, int n) {
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}
int scs(string a, string b, int m, int n) {
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int i = 0; i <= n; i++)
        dp[0][i] = i;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
        }
    }
    return dp[m][n];
}
int solve(string a, string b, int m, int n) {
    // int lcs_res = lcs(a, b, m, n);
    // return m + n - lcs_res;

    // using scs
    return scs(a, b, m, n);
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        cout << solve(a, b, a.size(), b.size()) << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
string solve(string a, string b, int m, int n) {
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j] <= dp[i][j - 1] ? dp[i][j - 1] : dp[i - 1][j];
        }
    }
    string res;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            // cout << a[i - 1] << string(1, a[i - 1]);
            res += string(1, a[i - 1]);
            i--;
            j--;
        } else {
            if (dp[i - 1][j] <= dp[i][j - 1]) {
                j--;
            } else {
                i--;
            }
        }
    }
    reverse(res.begin(), res.end());
    return res;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a;
        b = a;
        reverse(b.begin(), b.end());
        cout << solve(a, b, a.size(), b.size()) << endl;
    }
    return 0;
}
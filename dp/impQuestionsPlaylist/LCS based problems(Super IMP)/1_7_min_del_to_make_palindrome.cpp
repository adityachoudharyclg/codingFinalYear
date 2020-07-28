#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(string a, int n) {
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    string b = a;
    reverse(b.begin(), b.end());
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return n-dp[n][n];
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        cout << solve(a, a.size()) << endl;
    }
    return 0;
}
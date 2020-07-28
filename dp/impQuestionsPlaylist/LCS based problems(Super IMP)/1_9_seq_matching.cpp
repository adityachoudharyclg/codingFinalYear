#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(string a, string b, int m, int n) {
    // Simple recursive logic
    bool dp[m + 1][n + 1];
    memset(dp, true, sizeof(dp));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        }
    }
    // lcs logic can also be used where if
    // lcs(a,b)=min(a.size(),b.size()) then return true 
    // else false;
    return dp[m][n];
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        string a, b;
        cin >> a >> b;
        cout << solve(a, b, m, n) << endl;
    }
    return 0;
}
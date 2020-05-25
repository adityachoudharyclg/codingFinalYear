#include <bits/stdc++.h>
#define ll long long
#define m 1000000007
using namespace std;
ll solve(int n) {
    ll dp[100][100] = {0};
    dp[1][1] = 1LL;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] += j * dp[i - 1][j] * 1LL + dp[i - 1][j - 1] * 1LL;
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += dp[n][i];
    }
    return ans;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n)<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll solve(int n, int r) {
    if (r >= n) {
        return 0;
    }
    ll dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        ll temp[i + 1];
        for (int j = 0; j < i + 1; j++) {
            temp[j] = ((((j - 1) < 0) ? 0 : dp[j - 1]) % mod + ((j > i) ? 0 : dp[j]) % mod) % mod;
        }
        for (int j = 0; j < i + 1; j++) {
            dp[j] = temp[j];
        }
    }
    return dp[r];
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(2*n, n) << endl;
    }
    return 0;
}
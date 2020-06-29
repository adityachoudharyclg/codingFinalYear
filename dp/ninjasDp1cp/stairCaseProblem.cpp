#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll solve(int n) {
    n = n * 1LL;
    ll dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i]=(dp[i-1]+dp[i-2])%mod;
        dp[i]=(dp[i]+dp[i-3])%mod;
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
        cout << solve(n) << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[10001];
void initializeDP() {
    int n=10000;
    ll i2 = 0, i3 = 0, i5 = 0;
    ll nm2 = 2;
    ll nm3 = 3;
    ll nm5 = 5;
    ll nextUgly = 1;

    dp[0] = 1;
    for (ll i = 1; i < n; i++) {
        nextUgly = min(nm2, min(nm3, nm5));
        dp[i] = nextUgly;
        if (nextUgly == nm2) {
            i2 = i2 + 1;
            nm2 = dp[i2] * 2;
        }
        if (nextUgly == nm3) {
            i3 = i3 + 1;
            nm3 = dp[i3] * 3;
        }
        if (nextUgly == nm5) {
            i5 = i5 + 1;
            nm5 = dp[i5] * 5;
        }
    }
}
ll solve(ll n){
    return dp[n-1];
}
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll t;
    cin >> t;
    initializeDP();
    while (t--) {
        ll n;
        cin >> n;
        cout << solve(n)<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll solve(ll n) {
    ll res;
    while (n % 2 == 0) {
        res = 2;
        n /= 2;
    }
    for (ll i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            res = i;
            n /= i;
        }
    }
    if (n > 2)
        return n;
    return res;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
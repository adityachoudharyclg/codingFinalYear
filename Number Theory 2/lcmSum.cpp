#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll eulerTotient(ll n) {
    ll phi[n + 1];
    for (ll i = 0; i <= n; i++) {
        phi[i] = i;
    }
    for (ll i = 2; i <= n; i++) {
        for (ll j = 2 * i; j <= n; j += i) {
            if (phi[i] == i) {
                phi[j] = (phi[j] * (i - 1) * 1LL) / i;
            }
        }
        if (phi[i] == i) {
            phi[i] = i - 1;
        }
    }
    return phi[n];
}
vector<ll> allDivisors(ll n) {
    vector<ll> res;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i == n / i) {
                res.push_back(i);
            } else {
                res.push_back(i);
                res.push_back(n / i);
            }
        }
    }
    return res;
}
ll solve(ll n) {
    vector<ll> divisors = allDivisors(n);
    ll total = 0;
    for (int i = 0; i < divisors.size(); i++) {
        total += eulerTotient(divisors[i]) * divisors[i];
    }
    return (n * (total + 1LL)) / 2;
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
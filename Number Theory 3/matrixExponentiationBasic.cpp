#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll** multiply(ll** a, ll** b) {
    ll** res = new ll*[2];
    for (ll i = 0; i < 2; i++) {
        res[i] = new ll[2]();
    }

    for (ll i = 0; i < 2; i++) {
        for (ll j = 0; j < 2; j++) {
            for (ll k = 0; k < 2; k++) {
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }
    return res;
}
ll** matrixExponentation(ll n) {
    if (n == 1) {
        ll** res = new ll*[2];
        for (ll i = 0; i < 2; i++) {
            res[i] = new ll[2]();
        }
        res[0][0] = 1;
        res[0][1] = 1;
        res[1][0] = 1;
        res[1][1] = 0;
        return res;
    }

    if (n % 2 == 0) {
        ll** res = matrixExponentation(n / 2);
        return multiply(res, res);
    }

    ll** sp = matrixExponentation(n - 1);
    ll** res = new ll*[2];
    for (ll i = 0; i < 2; i++) {
        res[i] = new ll[2]();
    }
    res[0][0] = 1;
    res[0][1] = 1;
    res[1][0] = 1;
    res[1][1] = 0;
    return multiply(res, sp);
}
ll solve(ll n) {
    if (n == 0||n==1) {
        return n;
    } 
    ll** res = matrixExponentation(n - 1);
    return res[0][0];
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
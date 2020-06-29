#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll pow(ll a, ll b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 0) {
        ll temp = pow(a, b / 2);
        return (temp * temp) % mod;
    }
    return (pow(a, b - 1) * a) % mod;
}

ll solve(int arr[], int n) {
    ll gcdRes = arr[0];
    ll prodRes = arr[0];
    for (int i = 1; i < n; i++) {
        gcdRes = __gcd(gcdRes, arr[i] * 1LL);
        prodRes = ((prodRes % mod) * (arr[i] % mod)) % mod;
    }
    // cout << prodRes << " " << gcdRes << endl;
    ll res = pow(prodRes, gcdRes);
    return res;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(arr, n) << endl;
    }
    return 0;
}
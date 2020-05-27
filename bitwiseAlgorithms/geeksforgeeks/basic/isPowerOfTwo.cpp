#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
string solve(ll n) {
    return n && (!(n & (n - 1)))?"YES":"NO";
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
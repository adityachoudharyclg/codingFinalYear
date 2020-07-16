#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
void solve(ll arr[], ll n) {
    stack<ll> s;

    ll arr1[n];
    for (ll i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();

        if (s.empty())
            arr1[i] = -1;
        else
            arr1[i] = s.top();

        s.push(arr[i]);
    }

    for (ll i = 0; i < n; i++)
        cout << arr1[i] << " ";
    cout << endl;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll arr[n];
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(arr, n);
    }
    return 0;
}
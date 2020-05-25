#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll solver(ll arr[], ll n) {
    sort(arr, arr + n, greater<ll>());
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        sum += (((ll)(1) << i) * arr[i]);
    }
    return sum;
}

int main() {
    ll n;

    cin >> n;

    ll arr[n];

    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << solver(arr, n);
    return 0;
}
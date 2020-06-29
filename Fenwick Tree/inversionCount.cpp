#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
void update(ll ele, ll index, ll* BIT,ll n) {
    while (index <= n) {
        BIT[index] += ele;
        index += index & (-index);
    }
}
ll query(ll index, ll* BIT) {
    ll total = 0;
    while (index > 0) {
        total += BIT[index];
        index -= index & (-index);
    }
    return total;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll* arr = new ll[n + 1]();
        ll* BIT = new ll[n + 1]();
        ll total = 0;
        pair<ll, ll> p[n];
        for (ll i = 1; i <= n; i++) {
            cin >> arr[i];
            p[i - 1].first = arr[i];
            p[i - 1].second = i;
        }
        sort(p, p + n);
        for (ll i = 1; i <= n; i++) {
            arr[p[i - 1].second] = i;
        }


        for (ll i = n; i >= 1; i--) {
            ll cnt = query(arr[i] - 1, BIT);
            // cout<<arr[i]<<" "<<cnt<<endl;
            total += cnt;
            update(1, arr[i], BIT,n);
        }
        cout << total << endl;
        delete[] arr;
        delete[] BIT;
    }
    return 0;
}
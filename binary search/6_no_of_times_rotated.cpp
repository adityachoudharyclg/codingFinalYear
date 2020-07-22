#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll pivotind(ll a[], ll st, ll end, ll n) {
    if (st > end) return 0;
    ll mid = (st + end) / 2;
    if (mid + 1 < n && a[mid + 1] < a[mid])
        return mid + 1;
    if (mid - 1 >= 0 && a[mid] < a[mid - 1])
        return mid;
    if (a[mid] > a[st])
        return pivotind(a, mid + 1, end, n);
    else if (a[mid] < a[end])
        return pivotind(a, st, mid - 1, n);
    else {
        ll res1 = pivotind(a, mid + 1, end, n);
        ll res2 = pivotind(a, st, mid - 1, n);
        if (res1 == 0)
            return res2;
        return res1;
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        cout << pivotind(a, 0, n - 1, n) << endl;
    }
    return 0;
}
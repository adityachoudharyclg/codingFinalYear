#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll merge(ll arr[], ll start, ll mid, ll end) {
    ll res[end - start + 1];
    ll i = start;
    ll j = mid + 1;
    ll k = 0;
    ll cnt = 0;
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            res[k++] = arr[i++];
        } else {
            cnt += (mid + 1 - i);
            res[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        res[k++] = arr[i++];
    }
    while (j <= end) {
        cnt += (mid + 1 - i);
        res[k++] = arr[j++];
    }
    for (ll i = 0; i < k; i++) {
        arr[start + i] = res[i];
    }
    return cnt;
}
ll inversion_count(ll arr[], ll start, ll end) {
    if (start >= end) {
        return 0;
    }
    ll mid = start + (end - start) / 2;
    ll l_cnt = inversion_count(arr, start, mid);
    ll r_cnt = inversion_count(arr, mid + 1, end);
    ll m_cnt = merge(arr, start, mid, end);
    return l_cnt + r_cnt + m_cnt;
}
ll solve(ll arr[], ll n) {
    return inversion_count(arr, 0, n - 1);
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
        cout << solve(arr, n) << endl;
    }
    return 0;
}
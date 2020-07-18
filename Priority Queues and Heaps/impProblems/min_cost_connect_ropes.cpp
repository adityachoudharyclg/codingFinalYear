#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pq_min(T) priority_queue<T, vector<T>, greater<T>>
using namespace std;
ll solve(ll arr[], ll n) {
    pq_min(ll) pq(arr, arr + n);
    ll cost = 0;
    while (pq.size() > 1) {
        ll x = pq.top();
        pq.pop();
        ll y = pq.top();
        pq.pop();
        cost += (x + y);
        pq.push(x + y);
    }
    return cost;
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
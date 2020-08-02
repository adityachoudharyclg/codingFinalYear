#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pp(t) pair<t, t>
#define pq_min priority_queue<ll, vector<ll>, greater<ll>>
using namespace std;
ll solve(ll speed[], ll efficiency[], ll n, ll k) {
    pq_min pq;
    vector<pp(ll)> input;
    for (ll i = 0; i < n; i++) {
        input.push_back({efficiency[i], speed[i]});
    }
    sort(input.begin(), input.end());
    ll sum_speed = 0, res = 0;
    for (ll i = n - 1; i >= 0; i--) {
        sum_speed = (sum_speed + input[i].second);
        pq.push(input[i].second);
        if (pq.size() > k) {
            sum_speed = (sum_speed - pq.top());
            pq.pop();
        }
        res = max(res, sum_speed * input[i].first);
    }
    return res % mod;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll speed[n], efficiency[n];
        for (ll i = 0; i < n; i++) {
            cin >> speed[i];
        }
        for (ll i = 0; i < n; i++) {
            cin >> efficiency[i];
        }
        ll k;
        cin >> k;
        cout << solve(speed, efficiency, n, k) << endl;
    }
    return 0;
}
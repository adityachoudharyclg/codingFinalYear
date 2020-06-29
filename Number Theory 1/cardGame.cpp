#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define ump(i, j) unordered_map<i, j>
using namespace std;
ll *primes = new ll[1000001];
void constructPrimes() {
    for (ll i = 0; i <= 1000000; i++)
        primes[i] = 1;
    primes[0] = primes[1] = 0;
    for (ll i = 2; i * i <= 1000000; i++) {
        if (primes[i]) {
            for (ll j = 2 * i; j <= 10000000; j += i) {
                primes[j] = 0;
            }
        }
    }
}

ll solve(ll arr[], ll n, ll k) {
    unordered_map<ll, ll> num_k, num_ans;
    ll temp_k = k;
    // For breaking k into factors
    for (ll i = 2; i * i <= k; i++) {
        if (primes[i]) {
            ll cnt = 0;
            while ((temp_k % i) == 0) {
                cnt++;
                temp_k = temp_k / i;
            }
            if (cnt > 0) {
                num_k[i] = cnt;
            }
        }
    }
    if (temp_k > 1) {
        num_k[temp_k] = 1;
    }
    // Make changes to optimize
    ll total = 0;
    for (ll i = 0; i < n; i++) {
        // Initializing ans
        for (ump(ll, ll)::iterator it = num_k.begin(); it != num_k.end(); it++) {
            num_ans[it->first] = 0;
        }
        // For breaking arr[i] into factors
        ll j = i;
        bool flag = false;
        while (j < n && !flag) {
            bool temp_flag = true;
            ll temp_ans = arr[j];
            for (ump(ll, ll)::iterator it = num_k.begin(); it != num_k.end(); it++) {
                ll cnt = 0;
                while ((temp_ans % (it->first)) == 0) {
                    cnt++;
                    temp_ans /= it->first;
                }
                num_ans[it->first] += cnt;
            }
            for (ump(ll, ll)::iterator it = num_k.begin(); it != num_k.end(); it++) {
                if (num_ans[it->first] < it->second)
                    temp_flag = false;
            }
            flag = temp_flag;
            if (flag) {
                break;
            }
            j++;
        }
        // cout<<"hello"<<j<<endl;
        if (flag) {
            total += (n - j);
        }
    }
    return total;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll arr[n];
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }
        constructPrimes();
        cout << solve(arr, n, k) << endl;
    }
    return 0;
}
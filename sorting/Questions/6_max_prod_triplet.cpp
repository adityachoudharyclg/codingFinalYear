#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll solve(ll arr[], ll n) {
    ll largest = LONG_LONG_MIN;
    ll sec_largest = LONG_LONG_MIN;
    ll third_largest = LONG_LONG_MIN;
    ll smallest = LONG_LONG_MAX;
    ll sec_smallest = LONG_LONG_MAX;
    for (ll i = 0; i < n; i++) {
        if (arr[i] > largest) {
            third_largest = sec_largest;
            sec_largest = largest;
            largest = arr[i];
        } else if (arr[i] > sec_largest) {
            third_largest = sec_largest;
            sec_largest = arr[i];
        } else if (arr[i] > third_largest) {
            third_largest = arr[i];
        }

        if (arr[i] < smallest) {
            sec_smallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < sec_smallest) {
            sec_smallest = arr[i];
        }
    }
    return max(largest * sec_largest * third_largest, smallest * sec_smallest * largest);
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
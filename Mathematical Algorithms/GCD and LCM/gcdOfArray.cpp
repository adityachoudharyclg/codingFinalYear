#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll solve(int arr[], int n) {
    ll gcdRes = arr[0];
    for (int i = 1; i < n; i++) {
        gcdRes = __gcd(gcdRes, arr[i] * 1LL);
    }
    // cout << prodRes << " " << gcdRes << endl;
    return gcdRes;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(arr, n) << endl;
    }
    return 0;
}
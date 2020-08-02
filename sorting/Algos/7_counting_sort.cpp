#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
void solve(int arr[], int n) {
    int k = 4;
    int c[k], d[n];
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
    // O(n)
    for (int i = 0; i < n; i++) {
        c[arr[i] - 1]++;
    }
    // O(k)
    for (int i = 1; i < k; i++) {
        c[i] = c[i] + c[i - 1];
    }
    // cout << "hello" << k << endl;
    // for (int i = 0; i < k; i++) {
    //     cout << c[i] << endl;
    // }
    // O(n)
    for (int i = 0; i < n; i++) {
        d[c[arr[i] - 1] - 1] = arr[i];
        c[arr[i] - 1]--;
    }

    for (int i = 0; i < n; i++) {
        cout << d[i] << " ";
    }
    cout << endl;
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
        solve(arr, n);
    }
    return 0;
}
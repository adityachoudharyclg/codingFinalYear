#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int arr[], int n) {
    int lis[n], lds[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++) {
        int ans = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] > arr[j] && ans < lis[j]) {
                ans = lis[j];
            }
        }
        lis[i] = 1 + ans;
    }
    lds[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        int ans = 0;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j] && ans < lds[j]) {
                ans = lds[j];
            }
        }
        lds[i] = 1 + ans;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (res < (lis[i] + lds[i] - 1)) {
            res = lis[i] + lds[i] - 1;
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cout << lis[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << lds[i] << " ";
    // }
    // cout << endl;
    return res;
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
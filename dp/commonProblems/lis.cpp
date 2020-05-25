#include <bits/stdc++.h>
#define ll long long
using namespace std;
void printDP(int dp[], int n) {
    for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
}
int lis(int arr[], int n) {
    int dp[n];
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        int ans = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (ans < dp[j] && arr[j] < arr[i]) {
                ans = dp[j];
            }
        }
        dp[i] = 1 + ans;
    }
    // printDP(dp,n);
    return *max_element(dp, dp + n);
}
// int lisBEST(int arr[], int n) {
//     for (int i = 0; i < n; i++) {
//     }
// }
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << lis(arr, n) << endl;
    }
    return 0;
}
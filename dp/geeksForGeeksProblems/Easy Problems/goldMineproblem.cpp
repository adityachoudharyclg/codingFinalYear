#include <bits/stdc++.h>
#define ll long long
// #define m 1000000007
using namespace std;
int solve(int arr[][20], int n, int m) {
    int direct[][2] = {{0, 1}, {-1, 1}, {1, 1}};
    int dp[20][20] = {0};
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            int ans = 0;
            for (int k = 0; k < 3; k++) {
                if (i >= direct[k][0] && (i - direct[k][0]) < n && j >= direct[k][1] && ans < dp[i - direct[k][0]][j - direct[k][1]]) {
                    ans = dp[i - direct[k][0]][j - direct[k][1]];
                }
            }
            dp[i][j] = ans + arr[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (res < dp[i][m - 1]) {
            res = dp[i][m - 1];
        }
    }
    return res;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[20][20];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        cout << solve(arr, n, m) << endl;
    }
    return 0;
}
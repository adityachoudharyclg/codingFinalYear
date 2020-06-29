#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int dp[500][500], input[500][500];
        int r, c;
        cin >> r >> c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> input[i][j];
            }
        }
        dp[r - 1][c - 1] = 1;
        for (int i = r - 2; i >= 0; i--) {
            dp[i][c - 1] = dp[i + 1][c - 1] - input[i][c - 1];
        }
        for (int i = c - 2; i >= 0; i--) {
            dp[r - 1][i] = dp[r - 1][i + 1] - input[r - 1][i];
        }
        for (int i = r - 2; i >= 0; i--) {
            for (int j = c - 2; j >= 0; j--) {
                int t = min(dp[i + 1][j] - input[i][j], dp[i][j + 1] - input[i][j]);
                dp[i][j] = t < 1 ? 1 : t;
            }
        }
        cout << dp[0][0] << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int eggs, int floors) {
    int dp[eggs + 1][floors + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= floors; i++) {
        dp[1][i] = i;
    }
    for (int i = 2; i <= eggs; i++) {
        for (int j = 1; j <= floors; j++) {
            int ans = INT_MAX;
            for (int k = 1; k <= j; k++) {
                if (ans > max(dp[i - 1][k - 1], dp[i][j - k])) {
                    ans = max(dp[i - 1][k - 1], dp[i][j - k]);
                }
            }
            dp[i][j]=1+ans;
        }
    }
    return dp[eggs][floors];
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int eggs, floors;
        cin >> eggs >> floors;
        cout << solve(eggs, floors) << endl;
    }
    return 0;
}
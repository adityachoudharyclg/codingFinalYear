#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(string s1, string s2, string s3) {
    int dp[s1.size() + 1][s2.size() + 1][s3.size() + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            for (int k = 1; k <= s3.size(); k++) {
                if (s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[k - 1]) {
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                } else {
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
                }
            }
        }
    }
    return dp[s1.size()][s2.size()][s3.size()];
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        cout<<solve(s1,s2,s3)<<endl;
    }
    return 0;
}
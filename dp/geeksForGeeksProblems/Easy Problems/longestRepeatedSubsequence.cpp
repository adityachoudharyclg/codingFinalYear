#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(string s) {
    int dp[s.size() + 1][s.size() + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 1; j <= s.size(); j++) {
            if(s[i-1]==s[j-1]&&i!=j){
                dp[i][j]=1+dp[i-1][j-1];
            } else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[s.size()][s.size()];
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}
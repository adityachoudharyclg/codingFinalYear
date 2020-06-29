#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll solve(string s) {
    ll dp[s.size() + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= s.size(); i++) {
        dp[i]=s[i-1]!='0'?dp[i-1]:0;
        if((((s[i-1]-'0')+(s[i-2]-'0')*10)>=10)&&(((s[i-1]-'0')+(s[i-2]-'0')*10)<=26)){
            dp[i]=(dp[i]+dp[i-2])%mod;
        }
    }
    return dp[s.size()];
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    while (s != "0") {
        cout << solve(s)<<endl;
        cin >> s;
    }
    return 0;
}
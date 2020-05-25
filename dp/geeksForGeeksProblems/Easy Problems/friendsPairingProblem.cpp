#include <bits/stdc++.h>
#define ll long long
#define m 1000000007
using namespace std;
int solve(int n) {
    ll dp[n + 1];
    for (int i = 0; i < n + 1; i++) {
        if(i<=2){
            dp[i]=i;
        } else{
            dp[i]=(((i-1)%m*(dp[i-2]%m))%m+(dp[i-1]%m))%m;
        }
        // cout<<dp[i]<<" ";
    }
    // cout<<endl;
    return dp[n];
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n)<<endl;
    }
    return 0;
}
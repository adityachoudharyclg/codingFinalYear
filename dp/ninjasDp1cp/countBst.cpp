#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll solve(int n){
    ll dp[n+1]={0};
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            dp[i]=(dp[i]+(dp[j]*dp[i-j-1])%mod)%mod;
        }
    }
    return dp[n];
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}
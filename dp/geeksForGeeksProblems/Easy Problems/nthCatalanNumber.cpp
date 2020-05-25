#include<bits/stdc++.h>
#define ll long long
#define m 1000000007
using namespace std;
ll dp[101]={0};
void initializeDP(){
    dp[0]=1;
    for(ll i=1;i<101;i++){
        for(ll j=0;j<i;j++){
            dp[i]+=(dp[j]*dp[i-j-1]);
        }
    }
    // for(ll i=0;i<100;i++)
    //     cout<<dp[i]<<" ";
}
ll solve(int n){
    return dp[n];
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t;
    cin>>t;
    // cout<<"hello"<<endl;
    initializeDP();
    while(t--){
        ll n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}
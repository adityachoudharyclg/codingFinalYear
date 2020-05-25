#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int m,int n){
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=m;i++)
        dp[1][i]=i;
    if(n>=16){
        return 0;
    }
    for(int i=2;i<=n;i++){
        // cout<<(1<<(i-1))<<endl;
        for(int j=1<<(i-1);j<=m;j++){
            if(j>1){
                dp[i][j]=dp[i][j-1]+dp[i-1][j/2];
            } else{
                dp[i][j]=dp[i][j-1];
            }
        }
    }
    return dp[n][m];
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        cout<<solve(m,n)<<endl;
    }
    return 0;
}
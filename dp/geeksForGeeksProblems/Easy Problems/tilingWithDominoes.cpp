#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
pair<int,int> helper(int n){
    if(n==0){
        return make_pair(1,0);
    } else if(n==1){
        return make_pair(0,1);
    }
    pair<int,int> resNminus1=helper(n-1);
    pair<int,int> resNminus2=helper(n-2);
    return make_pair(resNminus2.first+2*resNminus1.second,resNminus1.first+resNminus2.second);
}
int solve(int n){
    return helper(n).first;
}
int solveDP(int n){
    pair<int,int> dp[n+1];
    dp[0]=make_pair(1,0);
    dp[1]=make_pair(0,1);
    for(int i=2;i<=n;i++){
        dp[i]=make_pair(dp[i-2].first+2*dp[i-1].second,dp[i-1].first+dp[i-2].second);
    }
    return dp[n].first;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<solveDP(n)<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int primes[],int primesSize,int k){
    int indexPrimes[primesSize],nm[primesSize];
    memset(indexPrimes,0,sizeof(indexPrimes));
    int dp[k+1];
    dp[0]=1;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<primesSize;i++){
        nm[i]=primes[i];
    }
    for(int i=1;i<=k;i++){
        int nextUgly=*min_element(nm,nm+primesSize);
        dp[i]=nextUgly;
        // cout<<"hello"<<nextUgly<<endl;
        for(int j=0;j<primesSize;j++){
            if(nm[j]==nextUgly){
                indexPrimes[j]+=1;
                nm[j]=dp[indexPrimes[j]]*primes[j];
            }
        }
    }
    // for(int i=0;i<=k;i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    return dp[k];
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int m;
        cin>>m;
        int primes[m];
        for (int i = 0; i < m; i++)
        {
            cin>>primes[i];
        }
        int k;
        cin>>k;
        cout<<solve(primes,m,k-1)<<endl;        
    }
    return 0;
}
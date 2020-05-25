#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll solve(int n,int k){
    ll same[n+1],diff[n+1];
    same[0]=0;
    diff[0]=0;
    same[1]=0;
    diff[1]=k;
    for(int i=2;i<=n;i++){
        same[i]=diff[i-1];
        diff[i]=((diff[i-1]%mod+diff[i-2]%mod)%mod*(k-1))%mod;
    }
    return (same[n]+diff[n])%mod;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        cout<<solve(n,k)<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll solve(int n){
    ll count=1;
    if(n<2){
        return 1;
    } 
    ll primes[n+1];
    memset(primes,1,sizeof(primes));
    primes[0]=0;
    primes[1]=0;
    // Calculating primes using seive
    for(int i=2;i*i<=n;i++){
        for(int j=i*i;j<=n;j+=i){
            primes[j]=0;
        }
    }
    // Counting factors using formula
    ll res=1;
    for(int i=0;i<=n;i++){
        if(primes[i]){
            ll p=i;
            ll total_cnt=0;
            while((n/p)>0){
                total_cnt+=(n/p);
                p*=i;
            }
            res=(res*(total_cnt+1))%mod;
        }
    }
    return res;
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
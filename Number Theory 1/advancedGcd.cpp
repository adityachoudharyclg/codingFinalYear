#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll solve(ll a,string b){
    ll newB=0;
    if(a==0){
        for(ll i=0;i<b.size();i++){
            newB=((newB*10)%mod+(b[i]-'0')%mod)%mod;
        }
        return newB;
    }
    for(ll i=0;i<b.size();i++){
        newB=((newB*10)%a+(b[i]-'0')%a)%a;
    }
    
    if(newB==0){
        return a;
    }
    return __gcd(a,newB);
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t;
    cin>>t;
    while(t--){
        ll a;
        string b;
        cin>>a>>b;
        cout<<solve(a,b)<<endl;
    }
    return 0;
}
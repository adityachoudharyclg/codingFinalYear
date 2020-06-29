#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    if(a==0||b==0){
        return 0;
    }
    return (a*b)/gcd(a,b);
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        cout<<lcm(a,b)<<" "<<gcd(a,b)<<endl;
    }
    return 0;
}
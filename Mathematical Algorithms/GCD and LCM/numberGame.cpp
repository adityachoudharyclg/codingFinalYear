#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll solve(int n){
    ll ans=1;
    for(int i=2;i<=n;i++){
        ans=(ans*1LL*i)/__gcd(ans,i*1LL);
    }
    return ans;
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
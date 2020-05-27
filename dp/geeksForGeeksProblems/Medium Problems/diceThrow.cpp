#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll solve(ll m,ll n,ll x){
    ll table[n + 1][x + 1]; 
    memset(table, 0, sizeof(table)); 
  
    for (ll j = 1; j <= m && j <= x; j++) 
        table[1][j] = 1; 
  
    for (ll i = 2; i <= n; i++) 
        for (ll j = 1; j <= x; j++) 
            for (ll k = 1; k <= m && k < j; k++) 
                table[i][j] += table[i-1][j-k]; 

    return table[n][x]; 
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t;
    cin>>t;
    while(t--){
        ll m,n,x;
        cin>>m>>n>>x;
        cout<<solve(m,n,x)<<endl;
    }
    return 0;
}
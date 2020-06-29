#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll* cntSet=new ll[750001];
ll solve(ll arr[],ll n){
    sort(arr,arr+n);
    for(ll i=0;i<=750000;i++){
        cntSet[i]=0;
    }
    for(ll i=0;i<n;i++){
        cntSet[arr[i]]=1;
    }
    for(ll i=0;i<n;i++){
        for(ll j=arr[i]*2;j<=arr[n-1];j+=arr[i]){
            if(cntSet[j]!=0){
                cntSet[j]=(cntSet[j]+cntSet[arr[i]])%mod;
            }
        }
    }
    ll total=0;
    for(ll i=0;i<n;i++){
        // cout<<"hello"<<cntSet[arr[i]]<<endl;
        total=(total+cntSet[arr[i]])%mod;
    }
    return total;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        for (ll i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        cout<<solve(arr,n)<<endl;        
    }
    return 0;
}
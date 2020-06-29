#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int n){
    int phi[n+1];
    for(int i=0;i<=n;i++){
        phi[i]=i;
    }
    for(int i=2;i<=n;i++){
        for(int j=2*i;j<=n;j+=i){
            if(phi[i]==i){
                phi[j]=(phi[j]*(i-1))/i;
            }
        }
        if(phi[i]==i){
            phi[i]=i-1;
        }
    }
    return phi[n];
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
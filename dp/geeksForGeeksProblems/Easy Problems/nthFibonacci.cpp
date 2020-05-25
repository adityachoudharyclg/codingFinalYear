#include<bits/stdc++.h>
#define ll long long
#define m 1000000007
using namespace std;
int solve(int n){
    int a=0;
    int b=1;
    int res;
    if(n==0){
        return 0;
    } else if(n==1){
        return 1;
    }
    for(int i=2;i<=n;i++){
        res=(a%m+b%m)%m;
        a=b;
        b=res;
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
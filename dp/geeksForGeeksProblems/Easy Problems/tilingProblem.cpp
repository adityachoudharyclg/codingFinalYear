#include<bits/stdc++.h>
#define ll long long
#define m 1000000007
using namespace std;
int helper(int n,int i){
    if(n==1){
        return 1;
    } else if(n<i){
        return 0;
    } else if(n==i){
        return 1;
    }
    int sp1=helper(n,i+1);
    int sp2=helper(n,i+2);
    return sp1+sp2;
}
int solve(int n){
    return helper(n,0);
}
ll solveDP(int n){
    ll a=0;
    ll b=1;
    ll res;
    if(n==0){
        return 0;
    } else if(n==1){
        return 1;
    }
    for(int i=2;i<=n;i++){
        res=(a+b)*1LL;
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
        cout<<solveDP(n+1)<<endl;
    }
    return 0;
}
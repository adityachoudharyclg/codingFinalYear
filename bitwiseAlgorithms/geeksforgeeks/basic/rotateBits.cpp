#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll solveLeft(ll n,int d){
    d=d%16;
    // cout<<d<<endl;
    while(d){
        int c=0;
        if(n&(1<<15)){
            c=1;
        }
        n=n<<1;
        if(c){
            n=n^1;
        }
        d--;
    }
    return n;
}
ll solveRight(ll n,int d){
    d=d%16;
    while(d){
        int c=0;
        if(n&1){
            c=1;
        }
        n=n>>1;
        if(c){
            n=n^(1<<15);
        }
        d--;
    }
    return n;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        ll n;
        int d;
        cin>>n>>d;
        cout<<solveLeft(n,d)<<endl;
        cout<<solveRight(n,d)<<endl;
    }
    return 0;
}
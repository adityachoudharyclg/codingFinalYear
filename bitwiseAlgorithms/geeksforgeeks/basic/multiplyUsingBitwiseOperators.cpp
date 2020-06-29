#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int a,int b){
    int res=0;
    while(b){
        if(b&1){
            res+=a;
        }
        a<<=1;
        b>>=1;
    }
    return res;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<solve(a,b)<<endl;
    }
    return 0;
}
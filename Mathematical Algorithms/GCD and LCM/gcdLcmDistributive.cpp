#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll lcm(int a,int b){
    if(a==0||b==0){
        return 0;
    }
    return (a*b*1LL)/(1LL*__gcd(a,b));
}
ll solve(int x,int y,int z){
    return lcm(x,__gcd(y,z));
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int x,y,z;
        cin>>x>>y>>z;
        cout<<solve(x,y,z)<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int n){
    // int i1=1,i2=1<<4;
    // while(i2!=(1<<8)){
    //     if(((n&i1)>0)^((n&i2)>0)){
    //         // cout<<i1<<"hello"<<i2<<(n&i1)<<(n&i2)<<endl;
    //         n=n^i1;
    //         n=n^i2;
    //         // cout<<n<<endl;
    //     }
    //     i1<<=1;
    //     i2<<=1;
    // }
    // return n;
    return ( (n & 0x0F) << 4 | (n & 0xF0) >> 4 ); 
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
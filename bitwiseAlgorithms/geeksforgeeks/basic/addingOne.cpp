#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int n){
    // sol 1
    return -(~n);

    // sol 2
    // int m = 1;  
      
    // // Flip all the set bits  
    // // until we find a 0  
    // while( n & m )  
    // {  
    //     n = n ^ m;  
    //     m <<= 1;  
    // }  
      
    // // flip the rightmost 0 bit  
    // n = n ^ m;  
    // return n;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<~1<<endl;
        cout<<solve(n)<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int helper(int n){
    int count=0;
    while(n)
    {
        int temp=n%2;
        count=(temp==0)?count+1:count;
        n=n/2;
    }    
    return count;
}
int solve(int n){
    return 1<<(helper(n));
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
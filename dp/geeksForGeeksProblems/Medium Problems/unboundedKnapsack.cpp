#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int weights[],int values[],int capacity,int n){
    int dp[capacity+1]; 
    memset(dp, 0, sizeof dp); 
    for (int i=0; i<=capacity; i++) 
      for (int j=0; j<n; j++) 
         if (weights[j] <= i) 
            dp[i] = max(dp[i], dp[i-weights[j]]+values[j]); 
  
    return dp[capacity]; 
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int n,capacity;
        cin>>n>>capacity;
        int values[n];
        for (int i = 0; i < n; i++)
        {
            cin>>values[i];
        }
        int weights[n];
        for (int i = 0; i < n; i++)
        {
            cin>>weights[i];
        }
        cout<<solve(weights,values,capacity,n)<<endl;        
    }
    return 0;
}
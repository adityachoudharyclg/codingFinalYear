#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int arr[],int n){
    int dp[n];
    dp[0]=1;
    for(int i=1;i<n;i++){
        int ans=0;
        for(int j=i-1;j>=0;j--){
            if(abs(arr[j]-arr[i])==1&&ans<dp[j]){
                ans=dp[j];
            }
        }
        dp[i]=1+ans;
    }
    return *max_element(dp,dp+n);
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        cout<<solve(arr,n)<<endl;        
    }
    return 0;
}
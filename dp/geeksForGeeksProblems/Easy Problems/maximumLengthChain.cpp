#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
bool comparator(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}
int solve(pair<int,int> arr[],int n){
    sort(arr,arr+n,comparator);
    int dp[n];
    dp[0]=1;
    for(int i=1;i<n;i++){
        int ans=0;
        for(int j=i-1;j>=0;j--){
            if(arr[j].second<arr[i].first&&ans<dp[j]){
                ans=dp[j];
            }
        }
        dp[i]=1+ans;
    }
    // for(int i=0;i<n;i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
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
        pair<int,int> arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i].first>>arr[i].second;
        }
        cout<<solve(arr,n)<<endl;        
    }
    return 0;
}
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int arr[],int n){
    int left[n],right[n];
    memset(left,0,sizeof(left));
    memset(right,0,sizeof(right));
    for(int i=1;i<n;i++){
        if(arr[i]>arr[i-1]){
            left[i]=left[i-1]+1;
        }
    }
    for(int i=n-2;i>=0;i--){
        if(arr[i]>arr[i+1]){
            right[i]=right[i+1]+1;
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<left[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<right[i]<<" ";
    // }
    // cout<<endl;
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=(max(left[i],right[i])+1);
    }
    return ans;
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
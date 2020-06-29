#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int arr[], int n,int capacity) {
    int dp[n+1][capacity+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=capacity;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=arr[i-1]){
                int temp=arr[i-1];
                while(temp<=j){
                    dp[i][j]+=dp[i-1][j-temp];
                    temp+=arr[i-1];
                }
            }
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=capacity;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[n][capacity];
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n,capacity;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin>>capacity;
        cout << solve(arr, n,capacity) << endl;
    }
    return 0;
}
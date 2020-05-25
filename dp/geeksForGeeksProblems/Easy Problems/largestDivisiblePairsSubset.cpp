#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int arr[], int n) {
    sort(arr,arr+n);
    int dp[n];
    memset(dp, 0, sizeof(dp));
    dp[n-1]=1;
    for(int i=n-2;i>=0;i--){
        int ans=0;
        for(int j=i+1;j<n;j++){
            if(arr[j]%arr[i]==0&&ans<dp[j]){
                ans=dp[j];
            }
        }
        dp[i]=ans+1;
    }
    return *max_element(dp,dp+n);
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(arr, n) << endl;
    }
    return 0;
}
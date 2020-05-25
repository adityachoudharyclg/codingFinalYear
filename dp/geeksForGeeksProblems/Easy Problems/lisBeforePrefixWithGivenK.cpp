#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int arr[], int n,int prefixIndex,int target) {
    int dp[prefixIndex+1];
    memset(dp,0,sizeof(dp));
    dp[0]=arr[0]<target?arr[0]:0;
    for(int i=1;i<=prefixIndex;i++){
        int ans=0;
        if(arr[i]>=target){
            dp[i]=0;
            continue;
        }
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i]&&ans<dp[j]){
                ans=dp[j];
            }
        }
        dp[i]=arr[i]+ans;
    }
    return *max_element(dp,dp+prefixIndex+1)+target;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int prefixIndex,kIndex;
        cin>>prefixIndex>>kIndex;
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(arr, n,prefixIndex,arr[kIndex])<<endl;
    }
    return 0;
}
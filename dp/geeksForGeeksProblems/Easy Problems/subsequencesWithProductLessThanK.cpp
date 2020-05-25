#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int arr[], int n, int prod, int k) {
    if(n==0){
        return prod<k;
    }
    int sp1=solve(arr+1,n-1,prod*arr[0],k);
    int sp2=solve(arr+1,n-1,prod,k);
    // cout<<arr[0]<<" "<<sp1<<" "<<sp2<<" "<<prod<<" "<<(prod<k)<<endl;
    return sp1+sp2;
}
int solve(int arr[],int n,int k){
    return solve(arr, n, 1, k)-1;
}
int solveDP(int arr[],int n,int k){
    int dp[k + 1][n + 1]; 
    memset(dp, 0, sizeof(dp)); 
  
    for (int i = 1; i <= k; i++) { 
        for (int j = 1; j <= n; j++) { 
            dp[i][j] = dp[i][j - 1]; 
            if (arr[j - 1] <= i && arr[j - 1] > 0) 
                dp[i][j] += dp[i/arr[j-1]][j-1] + 1; 
        } 
    } 
    return dp[k][n]; 
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solveDP(arr, n, k) << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int arr[], int n) {
    int dp[n];
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1])
        {
            dp[i]=1+dp[i-1];
        }
        else
            dp[i]=1;
    }
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>arr[i+1]&&dp[i]<=dp[i+1])
        {
            dp[i]=1+dp[i+1];
        }
    }
    int tot=0;
    for(int i=0;i<n;i++)
        tot+=dp[i];
    return tot;
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
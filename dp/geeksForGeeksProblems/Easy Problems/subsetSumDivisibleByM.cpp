#include <bits/stdc++.h>
#define ll long long
// #define m 1000000007
using namespace std;
bool solve(int arr[], int n, int m) {
    if (n > m)
        return true;

    bool dp[m];
    memset(dp, false, m);

    for (int i = 0; i < n; i++) {
        if (dp[0]) {
            return true;
        }

        bool temp[m];
        memset(temp, false, m);
        for (int j = 0; j < m; j++) {
            if (dp[j] == true) {
                if (dp[(j + arr[i]) % m] == false) {
                    temp[(j + arr[i]) % m] = true;
                }
            }
        }
        for(int i=0;i<m;i++){
            dp[i]=temp[i]==true?temp[i]:dp[i];
        }
        dp[(arr[i]%m)]=true;
    }
    return dp[0];
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(arr, n, m) << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
// #define 10000000 10000000
using namespace std;
void printDP(int dp[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == 10000000) {
                cout << "INF"
                     << " ";
            } else {
                cout << dp[i][j] << " ";
            }
        }
        cout << endl;
    }
}
void solve(int arr[][100], int n) {
    int dp[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = arr[i][j];
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    printDP(dp, n);
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[100][100];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                string s;
                cin >> s;
                if (s == "INF") {
                    arr[i][j] = 10000000;
                } else {
                    arr[i][j] = stoi(s);
                }
            }
        }
        solve(arr, n);
    }
    return 0;
}
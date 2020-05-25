#include <bits/stdc++.h>
#define ll long long
using namespace std;
int solveRec(int arr[], int start, int end, int dp[][100]) {
    if ((end - start + 1) < 3) {
        return 0;
    } else if ((end - start + 1) == 3) {
        return arr[start] * arr[start + 1] * arr[end];
    } else if (dp[start][end] != 0) {
        return dp[start][end];
    }
    int ans = INT_MAX;
    for (int i = start + 1; i < end; i++) {
        int a;
        if (dp[start][i] != 0) {
            a = dp[start][i];
        } else {
            a = solveRec(arr, start, i, dp);
            dp[start][i] = a;
        }
        int b;
        if (dp[i][end] != 0) {
            b = dp[i][end];
        } else {
            b = solveRec(arr, i, end, dp);
            dp[i][end] = b;
        }
        int c = arr[start] * arr[i] * arr[end];
        if (ans > (a + b + c)) {
            ans = a + b + c;
        }
    }
    dp[start][end] = ans;
    return ans;
}
int solveRec(int arr[], int n) {
    int dp[100][100] = {0};
    int ans = solveRec(arr, 0, n - 1, dp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%6d", dp[i][j]);
        }
        cout << endl;
    }
    return ans;
}
void printDP(ll dp[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%12lld", dp[i][j]);
        }
        cout << endl;
    }
}
void printDP(int dp[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", dp[i][j]);
        }
        cout << endl;
    }
}
ll solveDP(int arr[], int n) {
    ll dp[100][100] = {0};
    for (int l = 2; l < n; l++) {
        for (int i = 0; i < n - l; i++) {
            ll ans = LONG_LONG_MAX;
            for (int j = i + 1; j < i + l; j++) {
                ll calc = 1LL * arr[i] * arr[j] * arr[i + l];
                if (ans > (dp[i][j] + dp[j][i + l] + calc)) {
                    ans = dp[i][j] + dp[j][i + l] + calc;
                }
            }
            dp[i][i + l] = ans;
        }
    }
    return dp[0][n - 1];
}
void constructHelper(int s[][100], int start, int end) {
    if ((end - start) <= 1) {
        cout << char(start + 'A');
        return;
    }
    cout << "(";
    constructHelper(s, start, s[start][end]);
    constructHelper(s, s[start][end], end);
    cout << ")";
}
void constructDP(int arr[], int n) {
    ll dp[100][100] = {0};
    int s[100][100] = {0};
    for (int l = 2; l < n; l++) {
        for (int i = 0; i < n - l; i++) {
            ll ans = LONG_LONG_MAX;
            int index = i + 1;
            for (int j = i + 1; j < i + l; j++) {
                ll calc = 1LL * arr[i] * arr[j] * arr[i + l];
                if (ans > (dp[i][j] + dp[j][i + l] + calc)) {
                    ans = dp[i][j] + dp[j][i + l] + calc;
                    index = j;
                }
            }
            dp[i][i + l] = ans;
            s[i][i + l] = index;
        }
    }
    constructHelper(s, 0, n - 1);
    cout << endl;
}
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        // cout << solveDP(arr, n) << endl;
        constructDP(arr, n);
    }
    return 0;
}
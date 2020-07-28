#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(string a, string b, int m, int n) {
    int lcSuffix[m + 1][n + 1];
    memset(lcSuffix, 0, sizeof(lcSuffix));
    int res = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                lcSuffix[i][j] = 1 + lcSuffix[i - 1][j - 1];
                res = max(res, lcSuffix[i][j]);
            } else {
                lcSuffix[i][j] = 0;
            }
        }
    }
    return res;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        string a, b;
        cin >> a >> b;
        cout << solve(a, b, m, n) << endl;
    }
    return 0;
}
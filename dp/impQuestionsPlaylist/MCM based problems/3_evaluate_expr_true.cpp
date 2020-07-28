#include <bits/stdc++.h>
#define ll long long
#define mod 1003
#define ppi pair<int, int>
using namespace std;
ppi helper(string a, int i, int j, ppi** dp) {
    // Base Case
    if (i == j) {
        return a[i] == 'T' ? make_pair(1, 0) : make_pair(0, 1);
    }
    if (dp[i][j].first != -1) {
        return dp[i][j];
    }
    // General case
    int true_cnt = 0, false_cnt = 0;
    for (int k = i + 1; k < j; k += 2) {
        ppi l = helper(a, i, k - 1, dp);
        ppi r = helper(a, k + 1, j, dp);
        switch (a[k]) {
            case '^':
                true_cnt += (l.first * r.second) % mod + (l.second * r.first) % mod;
                false_cnt += (l.first * r.first) % mod + (l.second * r.second) % mod;
                break;
            case '&':
                true_cnt += (l.first * r.first) % mod;
                false_cnt += (l.second * r.second) % mod + (l.first * r.second) % mod + (l.second * r.first) % mod;
                break;
            case '|':
                true_cnt += (l.first * r.first) % mod + (l.first * r.second) % mod + (l.second * r.first) % mod;
                false_cnt += (l.second * r.second) % mod;
                break;
        }
        true_cnt = true_cnt % mod;
        false_cnt = false_cnt % mod;
    }
    dp[i][j] = make_pair(true_cnt, false_cnt);
    return dp[i][j];
}
int solve(string a) {
    ppi** dp = new ppi*[a.size()];
    for (int i = 0; i < a.size(); i++) {
        dp[i] = new ppi[a.size()];
        for (int j = 0; j < a.size(); j++) {
            dp[i][j] = make_pair(-1, -1);
        }
    }
    return helper(a, 0, a.size() - 1, dp).first;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        cout << solve(a);
    }
    return 0;
}
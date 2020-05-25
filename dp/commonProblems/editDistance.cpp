#include <bits/stdc++.h>
#define ll long long
using namespace std;
int solveRec(string s1, string s2) {
    if (s1.size() == 0) {
        return s2.size();
    }
    if (s2.size() == 0) {
        return s1.size();
    }
    if (s1[0] == s2[0]) {
        return solveRec(s1.substr(1), s2.substr(1));
    }
    int insertOpr = solveRec(s1, s2.substr(1));
    int removeOpr = solveRec(s1.substr(1), s2);
    int replaceOpr = solveRec(s1.substr(1), s2.substr(1));
    return min(insertOpr, min(removeOpr, replaceOpr)) + 1;
}
int solveDP(string s1, string s2) {
    int dp[s1.size() + 1][s2.size() + 1];
    for (int i = 0; i < s1.size() + 1; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j < s2.size() + 1; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    }
    return dp[s1.size()][s2.size()];
}
void constructDP(string s1, string s2) {
    int dp[s1.size() + 1][s2.size() + 1];
    for (int i = 0; i < s1.size() + 1; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j < s2.size() + 1; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    }
    vector<string> res;
    int i = s1.size(), j = s2.size();
    while (i >= 0 && j >= 0) {
        if (s1[i - 1] == s2[j - 1]) {
            i--;
            j--;
        } else {
            int insert = dp[i][j - 1];
            int remove = dp[i - 1][j];
            int replace = dp[i - 1][j - 1];
            int flag = insert < remove ? (insert < replace ? 0 : 1) : (remove < replace ? 2 : 1);
            string s;
            switch (flag) {
                case 0:
                    s = string("INSERT ") + string(1, s2[j - 1]);
                    res.push_back(s);
                    j--;
                    break;
                case 1:
                    s = string("REPLACE ") + string(1, s1[i - 1]) + string(" WITH ") + string(1, s2[j - 1]);
                    res.push_back(s);
                    i--;
                    j--;
                    break;
                case 2:
                    s = string("DELETE ") + string(1, s1[i - 1]);
                    res.push_back(s);
                    i--;
                    break;

                default:
                    break;
            }
        }
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        string s1, s2;
        cin >> s1 >> s2;
        // cout<<s1<<s2<<endl;
        cout << solveDP(s1, s2) << endl;
        constructDP(s1, s2);
    }
    return 0;
}
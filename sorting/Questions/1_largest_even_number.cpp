#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
string solve(string s) {
    int c[10];
    memset(c, 0, sizeof(c));
    string res(s.size(), '0');
    for (int i = 0; i < s.size(); i++) {
        c[s[i] - '0']++;
    }

    for (int i = 9; i > 0; i--) {
        c[i - 1] = c[i - 1] + c[i];
    }

    for (int i = 0; i < s.size(); i++) {
        // cout << (s[i] - '0') << " " << c[s[i] - '0'] - 1 << endl;
        res[c[s[i] - '0'] - 1] = s[i];
        c[s[i] - '0']--;
    }

    if ((res[res.size() - 1] - '0') % 2) {
        int index = -1;
        for (int i = res.size() - 1; i >= 0; i--) {
            if (res[i] % 2 == 0) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            res = res.substr(0, index) + res.substr(index + 1, s.size() - index - 1) + res.substr(index, 1);
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
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}
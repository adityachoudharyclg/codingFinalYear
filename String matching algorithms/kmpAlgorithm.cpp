#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
// longest prefix which is also suffix
int* lps(string pattern) {
    int* lps = new int[pattern.size()]();
    lps[0] = 0;
    int i = 1;
    int j = 0;
    while (i < pattern.size()) {
        if (pattern[i] == pattern[j]) {
            lps[i] = 1 + j;
            i++;
            j++;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    // for(int i=0;i<pattern.size();i++){
    //     cout<<lps[i]<<" ";
    // }
    // cout<<endl;
    return lps;
}
int solve(string s, string p) {
    int i = 0, j = 0;
    int* lpsArr = lps(p);
    int index = 0;
    while (i < s.size() && j < p.size()) {
        if (s[i] == p[j]) {
            i++;
            j++;
        } else {
            if (j != 0) {
                j = lpsArr[j - 1];
            } else {
                i++;
                index = i;
            }
        }
    }
    return j == p.size() ? (index) : -1;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        string s, p;
        cin >> s >> p;
        lps(p);
        cout << solve(s, p) << endl;
    }
    return 0;
}
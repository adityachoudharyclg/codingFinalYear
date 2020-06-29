#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(string s) {
    int maxi = 0;
    for (int i = 0; i < s.size(); i++) {
        int l, r;
        // odd length
        l = r = i;
        while (s[l] == s[r] && l >= 0 && r < s.size()) {
            l--;
            r++;
        }
        maxi = max(maxi, r - l - 1);
        // cout<<"1 "<<l<<" "<<r<<" "<<maxi<<endl;
        // even length
        if (i!=s.size()-1&&s[i] == s[i + 1]) {
            l = i;
            r = i + 1;
            while (s[l] == s[r] && l >= 0 && r < s.size()) {
                l--;
                r++;
            }
            maxi = max(maxi, r - l - 1);
            // cout<<"2 "<<l<<" "<<r<<" "<<maxi<<endl;
        }
    }
    return maxi;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
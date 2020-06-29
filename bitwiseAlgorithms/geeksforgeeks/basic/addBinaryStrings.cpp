#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
string solve(string s1, string s2) {
    string res(max(s1.size(), s2.size()), '0');
    if (s1.size() < s2.size()) {
        s1 = string((s2.size() - s1.size()), '0') + s1;
    } else if (s1.size() > s2.size()) {
        s2 = string((s1.size() - s2.size()), '0') + s2;
    }
    int i = s1.size() - 1, sum = 0, carry = 0;
    while (i >=0) {
        int a = (s1[i] - '0');
        int b = (s2[i] - '0');
        int c = carry;
        carry = (a & b) ^ (b & c) ^ (c & a);
        res[i] = sum + '0';
        i--;
    }
    if (carry) {
        res = "1" + res;
    }
    return res;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}
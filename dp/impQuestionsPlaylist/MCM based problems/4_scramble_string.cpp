#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define ump unordered_map<string, bool>
using namespace std;
bool helper(string a, string b, ump& hashmap) {
    // Base case
    if (a.size() != b.size())
        return false;
    if (a == b)
        return true;
    if (a.size() == 1)
        return false;

    // General case
    // cout << hashmap.count(a + b) << endl;
    string key = a + b;
    if (hashmap.count(key) > 0)
        return hashmap[key];
    int n = a.size();
    for (int i = 1; i < n; i++) {
        // cout << "hello" << endl;
        bool l_r = helper(a.substr(0, i), b.substr(n - i, i), hashmap);
        bool r_l = helper(a.substr(i, n - i), b.substr(0, n - i), hashmap);
        bool l_l = helper(a.substr(0, i), b.substr(0, i), hashmap);
        bool r_r = helper(a.substr(i, n - i), b.substr(i, n - i), hashmap);

        if ((l_l && r_r) || (l_r && r_l)) {
            hashmap[key] = true;
            // cout << hashmap[key] << hashmap.count(key) << endl;
            return true;
        }
    }
    hashmap[key] = false;
    return false;
}
bool solve(string a, string b) {
    ump hashmap;
    bool res = helper(a, b, hashmap);
    for (ump::iterator it = hashmap.begin(); it != hashmap.end(); it++) {
        cout << it->first << endl;
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
        cout << solve(a, b);
    }
    return 0;
}

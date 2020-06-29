#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
void build(int* Z, string str) {
    int l, r;
    l = r = 0;
    int n = str.size();
    for (int i = 1; i < n; i++) {
        if (i > r) {  // when i isnt in l....r range

            // Z for this i doesnt exists
            // Calculating for match
            l = i;
            r = i;
            while (r < n && str[r - l] == str[r]) {
                r++;
            }
            Z[i] = r - l;
            r--;
        } else {
            int k = i - l;
            if (Z[k] <= r - i) {
                // lies b/w l and r
                // Z will exist previously
                Z[i] = Z[k];
            } else {
                // Aage aur bada ans mil skta hai.
                l = i;
                // Some part included, some part to add
                // r ko change nhin kra kyunki r jahan pe hai wahan tk ka matched hai
                while (r < n && str[r - l] == str[r]) {
                    r++;
                }
                Z[i] = r - l;
                r--;
            }
        }
    }
}
void searchString(string text, string pattern) {
    string str = pattern + "$" + text;
    int n = str.size();
    int* Z = new int[n]();
    build(Z, str);
    for (int i = 0; i < n; i++) {
        if (Z[i] == pattern.size()) {
            cout << i - pattern.size() - 1 << " ";
        }
    }
    cout << endl;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        string s, p;
        cin >> s >> p;
        searchString(s, p);
    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
void solve(int n) {
    if (n >= 2) {
        cout << 2 << endl;
    } else if (n < 2) {
        return;
    }
    for (int i = 3; i <= n; i += 2) {
        bool flag = true;
        for (int j = 3; j * j <= i; j += 2) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << i << endl;
        }
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}
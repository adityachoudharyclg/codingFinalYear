#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int setBitsCount(int n) {
    int count = 0;
    while (n) {
        n = n & (n - 1);
        count++;
    }
    return count;
}
int solve(int n) {
    if (setBitsCount(n) == 1) {
        int temp = 1, pos = 1;
        while (temp <= n) {
            if (!(n ^ temp)) {
                // cout<<temp<<" "<<pos<<endl;
                return pos;
            }
            temp <<= 1;
            pos++;
        }
    }
    return -1;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
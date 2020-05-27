#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int setBitCount(int n) {
    int count = 0;
    while (n) {
        n = n & (n - 1);
        count++;
    }
    return count;
}
int solve(int a, int b) {
    int res = a ^ b;
    return setBitCount(res);
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }
    return 0;
}
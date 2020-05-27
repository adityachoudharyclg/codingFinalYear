#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int n) {
    int count = 0;
    while (n) {
        n=n&(n-1);
        count++;
    }
    return count;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n)<<endl;
    }
    return 0;
}
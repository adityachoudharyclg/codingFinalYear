#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
bool solve(int n) {
    list<int> s;
    while (n % 2 == 0) {
        s.push_back(2);
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            s.push_back(i);
            n /= i;
        }
    }
    if (n > 2) {
        s.push_back(n);
    }
    return s.size() == 3;//add another condition for correction
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
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
void solve(int n) {
    bool primes[n + 1];
    for (int i = 0; i <= n; i++) {
        primes[i] = true;
    }
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (primes[i]) {
            cout << i << " ";
        }
    }
    cout<<endl;
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
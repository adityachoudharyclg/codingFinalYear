#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
void solve(int n) {
    while (n % 2 == 0) {
        cout << 2 << " ";
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            cout << i << " ";
            n = n / i;
        }
    }
    if (n > 2)  
        cout << n << " ";
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
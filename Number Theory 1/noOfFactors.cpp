#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int* cntPrimes = new int[1000001]();
int** res = new int*[11];
void computeCntPrimes() {
    int* primes = new int[1000001]();
    for (int i = 0; i <= 1000000; i++) {
        primes[i] = 1;
        cntPrimes[i] = 0;
    }
    primes[0] = 0;
    primes[1] = 0;
    for (int i = 2; i * i <= 1000000; i++) {
        for (int j = i * i; j <= 1000000; j += i) {
            primes[j] = 0;
        }
    }

    for (int i = 2; i <= 1000000; i++) {
        if (primes[i]) {
            for (int j = i; j <= 1000000; j += i) {
                cntPrimes[j] += 1;
            }
        }
    }
    // for (int i = 1; i <= 1000000; i++) {
    //     cntPrimes[i] += cntPrimes[i - 1];
    //     cout << cntPrimes[i] << endl;
    // }
    for (int i = 0; i <= 10; i++) {
        res[i] = new int[1000001]();
        for (int j = 0; j <= 1000000; j++) {
            res[i][j] = 0;
        }
    }
    for (int i = 1; i <= 1000000; i++) {
        res[cntPrimes[i]][i]++;
    }
    for (int i = 0; i <= 10; i++) {
        for (int j = 1; j <= 1000000; j++) {
            res[i][j] += res[i][j - 1];
        }
    }
}
int solve(int a, int b, int n) {
    return res[n][b] - res[n][a - 1];
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    computeCntPrimes();
    while (t--) {
        int a, b, n;
        cin >> a >> b >> n;
        cout << solve(a, b, n) << endl;
    }
    return 0;
}
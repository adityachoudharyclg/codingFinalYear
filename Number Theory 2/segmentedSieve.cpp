#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
bool* primes = new bool[10001];
vector<int>* primesList = new vector<int>();
void constructPrimes() {
    for (int i = 0; i < 10001; i++) {
        primes[i] = true;
    }
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= 10000; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= 10000; j += i) {
                primes[j] = false;
            }
        }
    }
    for (int i = 0; i <= 10000; i++) {
        if (primes[i]) {
            primesList->push_back(i);
        }
    }
    delete[] primes;
}
void solve(int l, int r) {
    bool* res = new bool[r - l + 1];
    for (int i = 0; i <= r - l; i++) {
        res[i] = true;
    }
    for (int i = 0; i < primesList->size(); i++) {
        int primeNum = primesList->at(i);
        int start = (l / primeNum) * primeNum;

        if (start < l) {
            start += primeNum;
        }

        for (int j = start; j <= r; j += primeNum) {
            res[j - l] = false;
        }
        
        if (start <= r && start == primeNum) {
            res[start - l] = true;
        }
    }

    for (int i = 0; i <= r - l; i++) {
        if (res[i]) {
            cout << (i + l) << endl;
        }
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    constructPrimes();
    while (t--) {
        int l, r;
        cin >> l >> r;

        solve(l, r);
        // cout << solve(l, r) << endl;
    }
    return 0;
}
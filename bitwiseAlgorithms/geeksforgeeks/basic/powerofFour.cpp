#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int isPowerOfFour(unsigned int n) {
    // Your code goes here
    cout<<n<<endl;
    if(n==0)
        return 0;
    while (n!=1) {
        if (n % 4 != 0) {
            return 0;
        }
        // cout<<"hello:"<<n<<endl;
        n = n >> 2;
    }
    return 1;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << isPowerOfFour(n) << endl;
    }
    return 0;
}
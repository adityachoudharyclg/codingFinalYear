#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
class Triplet {
   public:
    ll gcd;
    ll x;
    ll y;
};
Triplet gcdExtendedEuclid(ll a, ll b) {
    //Base Case
    if (b == 0) {
        Triplet myAns;
        myAns.gcd = a;
        myAns.x = 1;
        myAns.y = 0;
        return myAns;
    }
    Triplet smallAns = gcdExtendedEuclid(b, a % b);
    //Extended euclid says

    Triplet myAns;
    myAns.gcd = smallAns.gcd;
    myAns.x = smallAns.y;
    myAns.y = (smallAns.x - ((a / b) * (smallAns.y)));
    return myAns;
}

ll modInverse(ll A, ll M) {
    ll x = gcdExtendedEuclid(A, M).x;
    return (x % M + M) % M;
}
ll solve(ll a, ll b, ll d) {
    if ((d % __gcd(a, b)) != 0) {
        return 0;
    } else if (d == 0) {
        return 1;
    }
    int temp=__gcd(a,b);
    a /= temp;
    b /= temp;
    d /= temp;

    ll smallestY = ((d % a) * modInverse(b, a)) % a;
    // cout<<"hello:"<<smallestY<<" "<<d<<endl;
    ll firstValue = d / b;
    if (d < smallestY * b) {
        return 0;
    }
    ll res = ((firstValue - smallestY) / a) + 1;
    return res;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        ll a, b, d;
        cin >> a >> b >> d;
        cout << solve(a, b, d) << endl;
    }
    return 0;
}
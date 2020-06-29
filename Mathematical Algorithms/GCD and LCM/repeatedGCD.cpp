#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
} 
void solve(ll n, ll x, ll y) 
{ 
    // Finding GCD of x and y. 
    ll g = gcd(x,y); 
  
    // Prll n, g times. 
    for (ll i = 0; i < g; i++) 
        cout << n; 
    cout<<endl;
} 
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t;
    cin >> t;
    while (t--) {
        ll x, y, z;
        cin >> x >> y >> z;
        solve(x, y, z);
    }
    return 0;
}
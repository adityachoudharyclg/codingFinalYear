#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int sumOfDigits(int n) {
    string s = to_string(n);
    int total = 0;
    for (int i = 0; i < s.size(); i++) {
        total+=(s[i]-'0');
    }
    return total;
}
bool solve(int n) {
    int actNum=n;
    if (n == 2) {
        return false;
    }
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
    if(n==actNum){
        return false;
    }
    if (n > 2) {
        s.push_back(n);
    }
    int total=0;
    for(list<int>::iterator it=s.begin();it!=s.end();it++){
        // cout<<*it<<" ";
        total+=(sumOfDigits(*it));
    }
    // cout<<endl;
    // cout<<"hello"<<total<<" "<<sumOfDigits(actNum)<<endl;
    return total==sumOfDigits(actNum);
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
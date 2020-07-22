#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(vector<int> arr, int ele) {
    if(!binary_search(arr.begin(), arr.end(), ele,greater<int>())){
        return -1;
    }
    int pos = lower_bound(arr.begin(), arr.end(), ele,greater<int>()) - arr.begin();
    return pos;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        int ele;
        cin >> ele;
        cout << solve(arr, ele) << endl;
    }
    return 0;
}
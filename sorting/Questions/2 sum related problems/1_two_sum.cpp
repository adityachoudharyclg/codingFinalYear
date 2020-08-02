#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define ump unordered_map<int, int>
using namespace std;
string solve(int arr[], int n, int target) {
    ump hashmap;
    for (int i = 0; i < n; i++) {
        if (hashmap.find(target - arr[i]) != hashmap.end())
            return string("Yes");
        hashmap[arr[i]] = 1;
    }
    return string("No");
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n, target;
        cin >> n >> target;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(arr, n, target) << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define ump unordered_map<int, int>
using namespace std;
int solve(int arr[], int n, int diff) {
    ump hashmap;
    for (int i = 0; i < n; i++) {
        hashmap[arr[i]]++;
    }
    int cnt = 0;
    for (auto it = hashmap.begin(); it != hashmap.end(); it++) {
        if (it->second != 0 && hashmap.find(diff + it->first) != hashmap.end()) {
            int a = it->first;
            int b = diff + it->first;
            if (a == b) {
                if (it->second >= 2) {
                    cnt++;
                }
            } else {
                cnt++;
            }

            hashmap[a] = 0;
            hashmap[b] = 0;
        }
    }
    return cnt;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n, diff;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> diff;
        cout << solve(arr, n, diff) << endl;
    }
    return 0;
}
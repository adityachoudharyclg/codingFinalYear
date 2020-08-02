#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define ump unordered_map<int, int>
using namespace std;
int solve(int arr[], int n, int target) {
    ump hashmap;
    for (int i = 0; i < n; i++) {
        hashmap[arr[i]]++;
    }
    int cnt = 0;
    for (ump::iterator it = hashmap.begin(); it != hashmap.end(); it++) {
        if (hashmap.find(target - it->first) != hashmap.end()) {
            int a = it->first;
            int b = target - it->first;
            if (a == b) {
                cnt += (hashmap[a] * (hashmap[a] - 1)) / 2;
            } else {
                cnt += hashmap[a] * hashmap[b];
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
#include <bits/stdc++.h>
#define ll long long
#define ppi pair<int, int>
#define ump unordered_map<int, ppi>
#define mod 1000000007
using namespace std;
void solve(int arr[], int n, int target) {
    ump hashmap;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            hashmap[arr[i] + arr[j]] = {i, j};
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (hashmap.find(target - (arr[i] + arr[j])) != hashmap.end()) {
                ppi p = hashmap[target - (arr[i] + arr[j])];
                if ((p.first != i && p.second != i) && (p.first != j && p.second != j)) {
                    cout << arr[i] << " " << arr[j] << " " << arr[p.first] << " " << arr[p.second] << " $";
                }
                hashmap.erase(arr[i] + arr[j]);
                hashmap.erase(target - (arr[i] + arr[j]));
            }
        }
    }
    cout << endl;
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
        solve(arr, n, target);
    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define ump unordered_map<int, int>
using namespace std;
void solve(int arr1[], int arr2[], int m, int n) {
    ump ele_cnt;
    vector<int> res;
    for (int i = 0; i < m; i++) {
        ele_cnt[arr1[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (ele_cnt[arr2[i]] != 0) {
            int k = ele_cnt[arr2[i]];
            while (k) {
                res.push_back(arr2[i]);
                k--;
            }
            ele_cnt[arr2[i]] = 0;
        }
    }
    vector<int> remains;
    for (auto it = ele_cnt.begin(); it != ele_cnt.end(); it++) {
        if (it->second != 0) {
            int k = it->second;
            while (k) {
                remains.push_back(it->first);
                k--;
            }
        }
    }
    sort(remains.begin(), remains.end());
    res.insert(res.end(), remains.begin(), remains.end());
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        int arr1[m], arr2[n];
        for (int i = 0; i < m; i++) {
            cin >> arr1[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        solve(arr1, arr2, m, n);
    }
    return 0;
}
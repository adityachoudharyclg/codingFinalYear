#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define ppi pair<int, int>
using namespace std;
ppi solve(int start[], int end[], int n) {
    int maxi = *max_element(end, end + n);
    int res[maxi + 2], diff[maxi + 2];
    memset(res, 0, sizeof(res));
    memset(diff, 0, sizeof(diff));
    for (int i = 0; i < n; i++) {
        diff[start[i]] += 1;
        diff[end[i] + 1] -= 1;
    }
    for (int i = 1; i <= maxi; i++) {
        res[i] = res[i - 1] + diff[i];
    }
    int cnt = *max_element(res, res + maxi + 1);
    int index = distance(res, max_element(res, res + maxi + 1));
    return {cnt, index};
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) {
            cin >> start[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> end[i];
        }
        ppi res = solve(start, end, n);
        cout << res.first << " " << res.second << endl;
    }
    return 0;
}
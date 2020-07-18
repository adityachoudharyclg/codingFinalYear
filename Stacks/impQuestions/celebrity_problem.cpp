#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int arr[][500], int n) {
    int a = 0;
    int b = n - 1;

    while (a < b) {
        if (arr[a][b])
            a++;
        else
            b--;
    }

    for (int i = 0; i < n; i++) {
        if ((i != a) && (arr[a][i] || !arr[i][a]))
            return -1;
    }

    return a;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[500][500];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        cout << solve(arr, n) << endl;
    }
    return 0;
}
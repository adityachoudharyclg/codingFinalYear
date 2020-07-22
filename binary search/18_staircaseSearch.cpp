#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(int arr[][500], int m, int n, int ele) {
    int i = 0;
    int j = n - 1;
    while (i < m && j >= 0) {
        if (arr[i][j] == ele) {
            return 1;
        } else if (arr[i][j] > ele) {
            j--;
        } else if (arr[i][j] < ele) {
            i++;
        }
    }
    return 0;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        int arr[500][500];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        int ele;
        cin >> ele;
        cout << solve(arr, m, n, ele) << endl;
    }
    return 0;
}
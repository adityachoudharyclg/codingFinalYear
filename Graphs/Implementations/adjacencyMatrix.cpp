#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int mat[n][n];
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin>>x>>y;
        mat[x][y] = 1;
        mat[y][x] = 1;
    }
    for (int i = 0; i < n; i++) {
        cout << i << ":";
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                cout << j << "->";
            }
        }
        cout << endl;
    }
    return 0;
}
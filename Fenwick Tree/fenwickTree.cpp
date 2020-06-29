#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int* BIT = new int[1000001]();
void updateBIT(int ele, int index, int n) {
    while (index <= n) {
        BIT[index] += ele;
        index += (index & (-index));
    }
}
int queryBIT(int index) {
    int total = 0;
    while (index > 0) {
        total += BIT[index];
        index -= (index & (-index));
    }
    return total;
}
void createBIT(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        updateBIT(arr[i], i, n);
    }
}
int solve(int l, int r) {
    l = l + 1;
    r = r + 1;
    return queryBIT(r) - queryBIT(l - 1);
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    createBIT(arr, n + 1);
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << solve(l, r) << endl;
    }
    return 0;
}
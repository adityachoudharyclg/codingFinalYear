#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int merge(int arr[], int start, int mid, int end) {
    int res[end - start + 1];
    int k = 0;
    int i = start;
    int j = mid + 1;
    int comp = 0;
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            res[k++] = arr[i++];
            comp++;
        } else {
            res[k++] = arr[j++];
            comp++;
        }
    }
    while (i <= mid) {
        res[k++] = arr[i++];
        comp++;
    }
    while (j <= end) {
        res[k++] = arr[j++];
        comp++;
    }
    // cout << k << endl;
    for (int i = 0; i < k; i++) {
        arr[start + i] = res[i];
    }
    return comp;
}
int helper(int arr[], int start, int end) {
    if (start >= end)
        return 0;
    // cout << "hello" << endl;
    int mid = start + (end - start) / 2;
    int left_comp = helper(arr, start, mid);
    int right_comp = helper(arr, mid + 1, end);
    int merge_comp = merge(arr, start, mid, end);
    return left_comp + right_comp + merge_comp;
}
void solve(int arr[], int n) {
    cout << helper(arr, 0, n - 1) << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(arr, n);
    }
    return 0;
}
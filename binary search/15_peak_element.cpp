#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int peekCalc(int arr[], int start, int end, int n) {
    if (start > end) {
        return -1;
    }
    int mid = start + (end - start) / 2;

    int flag = true;
    if ((mid - 1 >= 0 && arr[mid - 1] >= arr[mid]) || (mid + 1 <= n - 1 && arr[mid + 1] >= arr[mid]))
        flag = false;
    if (flag) {
        return mid;
    } else if ((mid - 1 >= 0 && arr[mid - 1] >= arr[mid]) && (mid + 1 <= n - 1 && arr[mid + 1] >= arr[mid])) {
        int res1 = peekCalc(arr, start, mid - 1, n);
        int res2 = peekCalc(arr, mid + 1, end, n);
        return res1 == -1 ? res2 : res1;
    } else if (mid - 1 >= 0 && arr[mid - 1] >= arr[mid]) {
        return peekCalc(arr, start, mid - 1, n);
    } else if (mid + 1 <= n - 1 && arr[mid + 1] >= arr[mid]) {
        return peekCalc(arr, mid + 1, end, n);
    }
    return -1;
}
int solve(int arr[], int n) {
    return peekCalc(arr, 0, n - 1, n);
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
        cout << solve(arr, n) << endl;
    }
    return 0;
}
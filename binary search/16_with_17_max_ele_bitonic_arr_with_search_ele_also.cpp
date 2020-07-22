#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int maxEleBitonic(int arr[], int start, int end, int size) {
    if (start > end) {
        return -1;
    }
    int mid = start + (end - start) / 2;
    int flag = true;
    if ((mid - 1 >= 0 && arr[mid - 1] > arr[mid]) || (mid + 1 < size && arr[mid + 1] > arr[mid])) {
        flag = false;
    }
    if (flag) {
        return mid;
    } else if (mid - 1 >= 0 && arr[mid - 1] > arr[mid]) {
        return maxEleBitonic(arr, start, mid - 1, size);
    } else if (mid + 1 < size && arr[mid + 1] > arr[mid]) {
        return maxEleBitonic(arr, mid + 1, end, size);
    }
    return -1;
}
int searchEle(int arr[], int start, int end, int ele, int sign) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == ele) {
            return mid;
        } else if (sign == 0) {
            if (arr[mid] < ele) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        } else if (sign == 1) {
            if (arr[mid] < ele) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }
    return -1;
}
int solve(int arr[], int n, int ele) {
    int pivot = maxEleBitonic(arr, 0, n - 1, n);
    // cout << pivot << endl;
    if (pivot != -1) {
        int res1 = searchEle(arr, 0, pivot, ele, 0);
        int res2 = searchEle(arr, pivot + 1, n - 1, ele, 1);
        return res1 != -1 ? res1 : res2;
    }
    return -1;
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
        int ele;
        cin >> ele;
        cout << solve(arr, n, ele) << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int merge(int arr[], int start, int mid, int end) {
    int res[end - start + 1];
    int i = start;
    int j = mid + 1;
    int k = 0;
    int cnt = 0;
    // Counting
    for (int i = start; i <= mid; i++) {
        while (j <= end && arr[i] > arr[j] * 2LL)
            j++;
        cnt += j - (mid + 1);
    }
    j = mid + 1;
    // Sorting portion
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            res[k++] = arr[i++];
        } else {
            res[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        res[k++] = arr[i++];
    }
    while (j <= mid) {
        res[k++] = arr[j++];
    }

    for (int i = 0; i < k; i++) {
        arr[start + i] = res[i];
    }

    // cout << "Cur res:"<< " " << start << " " << mid << " " << end << " " << cnt << endl;
    return cnt;
}
int reverse_pair(int arr[], int start, int end) {
    if (start >= end) {
        return 0;
    }
    int mid = start + (end - start) / 2;
    int l = reverse_pair(arr, start, mid);
    int r = reverse_pair(arr, mid + 1, end);
    int merge_cnt = merge(arr, start, mid, end);
    return l + r + merge_cnt;
}
int solve(int arr[], int n) {
    return reverse_pair(arr, 0, n - 1);
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
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int cnt;
int partition(int arr[], int start, int end) {
    int part_ele = arr[end];
    int part_index = start;
    int i = start;
    while (i <= end - 1) {
        cnt++;
        if (part_ele > arr[i]) {
            swap(arr[i], arr[part_index++]);
        }
        i++;
    }
    swap(arr[part_index], arr[end]);
    return part_index;
}
void helper(int arr[], int start, int end) {
    if (start >= end)
        return;
    // cout << "hello" << endl;
    int pivot = partition(arr, start, end);
    helper(arr, start, pivot - 1);
    helper(arr, pivot + 1, end);
}
void solve(int arr[], int n) {
    cnt = 0;
    helper(arr, 0, n - 1);
    cout << cnt << endl;
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
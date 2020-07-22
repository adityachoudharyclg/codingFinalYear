#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int pivot_index(vector<int> arr, int start, int end) {
    if (end < start)
        return 0;
    int mid = start + (end - start) / 2;
    if (mid < end && arr[mid] > arr[mid + 1])
        return mid + 1;
    if (mid > start && arr[mid - 1] > arr[mid])
        return mid;
    if (arr[mid] > arr[start])
        return pivot_index(arr, mid + 1, end);
    else if (arr[mid] < arr[end])
        return pivot_index(arr, start, mid - 1);

    return 0;
}
int pivot_index_easy(vector<int> arr) {
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        int next = (mid + 1) % arr.size();
        int prev = (mid - 1 + arr.size()) % arr.size();
        if (arr[mid] <= arr[next] && arr[mid] <= arr[prev]) {
            return mid;
        }
        if (arr[start] <= arr[mid]) {
            start = mid + 1;
        } else if (arr[mid] <= arr[end]) {
            end = mid - 1;
        }
    }
    return 0;
}
int solve(vector<int> arr, int ele) {
    // int pivot = pivot_index(arr, 0, arr.size() - 1);
    int pivot = pivot_index_easy(arr);
    if (binary_search(arr.begin(), arr.begin() + pivot, ele)) {
        return lower_bound(arr.begin(), arr.begin() + pivot, ele) - arr.begin();
    } else if (binary_search(arr.begin() + pivot, arr.end(), ele)) {
        return lower_bound(arr.begin() + pivot, arr.end(), ele) - arr.begin();
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
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        int ele;
        cin >> ele;
        cout << solve(arr, ele) << endl;
    }
    return 0;
}
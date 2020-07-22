#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(vector<int> arr, int ele) {
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == ele) {
            return mid;
        } else if (mid - 1 >= start && arr[mid - 1] == ele) {
            return mid - 1;
        } else if (mid + 1 <= end && arr[mid + 1] == ele) {
            return mid + 1;
        } else if (ele > arr[mid]) {
            start = mid + 2;
        } else {
            end = mid - 2;
        }
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
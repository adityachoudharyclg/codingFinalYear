#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int solve(vector<int> arr, int ele) {
    int start = 0;
    int end = arr.size() - 1;
    int res = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == ele) {
            res = mid;
            break;
        } else if (ele > arr[mid]) {
            res = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return res;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ele;
        cin >> ele;
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        cout << solve(arr, ele) << endl;
    }
    return 0;
}
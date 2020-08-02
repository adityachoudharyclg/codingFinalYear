#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
void solve(int arr[], int n) {
    int comparisons = 0;
    for (int i = 1; i < n; i++) {
        int cur_ele = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > cur_ele) {
            arr[j + 1] = arr[j];
            j--;
            comparisons++;
        }
        arr[j + 1] = cur_ele;
    }
    cout << comparisons << endl;
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
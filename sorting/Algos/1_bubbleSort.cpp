#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
void solve(int arr[], int n) {
    int comparsions = 0;
    for (int i = 0; i < n; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swapped = true;
                swap(arr[j], arr[j + 1]);
            }
            comparsions++;
        }
        if (!swapped)
            break;
    }
    cout << comparsions << endl;
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
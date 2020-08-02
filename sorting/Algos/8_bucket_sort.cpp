#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
void printArr(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void insertion_sort(vector<float>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        float ele = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > arr[i]) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = ele;
    }
}
void solve(float arr[], int n) {
    vector<float> buckets[10];
    for (int i = 0; i < n; i++) {
        buckets[int(10 * arr[i])].push_back(arr[i]);
    }
    for (int i = 0; i < 10; i++) {
        insertion_sort(buckets[i]);
    }
    int k = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[k++] = buckets[i][j];
        }
    }

    printArr(arr, n);
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        float arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(arr, n);
    }
    return 0;
}
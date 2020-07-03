#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
void solve(int arr[], int n) {
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            maxHeap.push(arr[i]);
            cout << arr[i] << endl;
        } else if ((i + 1) % 2 == 0) {
            // Even number of elements wala case
            if (maxHeap.size() > minHeap.size()) {
                int top = maxHeap.top();
                if (arr[i] > top) {
                    minHeap.push(arr[i]);
                } else {
                    int temp = maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(temp);
                    maxHeap.push(arr[i]);
                }
            } else {
                int top = maxHeap.top();
                if (arr[i] <= top) {
                    maxHeap.push(arr[i]);
                } else {
                    minHeap.push(arr[i]);
                    int temp = minHeap.top();
                    minHeap.pop();
                    maxHeap.push(temp);
                }
            }
            cout << (maxHeap.top() + minHeap.top()) / 2 << endl;
        } else {
            // Odd Number of elements
            if (arr[i] < maxHeap.top()) {
                maxHeap.push(arr[i]);
                cout << maxHeap.top() << endl;
            } else {
                minHeap.push(arr[i]);
                cout << minHeap.top() << endl;
            }
        }
    }
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
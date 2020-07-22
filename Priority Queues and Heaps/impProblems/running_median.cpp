#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
void addEle(priority_queue<int, vector<int>>& lower, priority_queue<int, vector<int>, greater<int>>& higher, int ele) {
    if (lower.empty() || ele <= lower.top()) {
        lower.push(ele);
    } else {
        higher.push(ele);
    }
}

void rebalance(priority_queue<int, vector<int>>& lower, priority_queue<int, vector<int>, greater<int>>& higher) {
    if (lower.size() <= higher.size()) {
        priority_queue<int, vector<int>>& smaller = lower;
        priority_queue<int, vector<int>, greater<int>>& bigger = higher;
        if ((bigger.size() - smaller.size()) >= 2) {
            smaller.push(bigger.top());
            bigger.pop();
        }
    } else {
        priority_queue<int, vector<int>, greater<int>>& smaller = higher;
        priority_queue<int, vector<int>>& bigger = lower;
        if ((bigger.size() - smaller.size()) >= 2) {
            smaller.push(bigger.top());
            bigger.pop();
        }
    }
}

double get_median(priority_queue<int, vector<int>>& lower, priority_queue<int, vector<int>, greater<int>>& higher) {
    if (lower.size() <= higher.size()) {
        priority_queue<int, vector<int>>& smaller = lower;
        priority_queue<int, vector<int>, greater<int>>& bigger = higher;
        if (smaller.size() == bigger.size()) {
            return ((double)smaller.top() + bigger.top()) / 2;
        } else {
            return bigger.top();
        }
    } else {
        priority_queue<int, vector<int>, greater<int>>& smaller = higher;
        priority_queue<int, vector<int>>& bigger = lower;
        if (smaller.size() == bigger.size()) {
            return ((double)smaller.top() + bigger.top()) / 2;
        } else {
            return bigger.top();
        }
    }
}
void solve(int arr[], int n) {
    priority_queue<int, vector<int>> lower;
    priority_queue<int, vector<int>, greater<int>> higher;
    for (int i = 0; i < n; i++) {
        int ele = arr[i];
        addEle(lower, higher, ele);
        rebalance(lower, higher);
        cout << get_median(lower, higher) << endl;
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    // cin >> t;
    t = 1;
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
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
vector<int> nsl_index(int arr[], int n) {
    stack<pair<int, int>> stk;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && arr[i] <= stk.top().second) {
            stk.pop();
        }
        if (stk.empty()) {
            res.push_back(-1);
        } else {
            res.push_back(stk.top().first);
        }
        stk.push(make_pair(i, arr[i]));
    }
    return res;
}

vector<int> nsr_index(int arr[], int n) {
    stack<pair<int, int>> stk;
    vector<int> res;
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && arr[i] <= stk.top().second) {
            stk.pop();
        }
        if (stk.empty()) {
            res.push_back(-1);
        } else {
            res.push_back(stk.top().first);
        }
        stk.push(make_pair(i, arr[i]));
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < n; i++) {
        if (res[i] == -1) {
            res[i] = n;
        }
    }
    return res;
}

int mah(int arr[], int n) {
    int res = 0;
    vector<int> nsl_res = nsl_index(arr, n);
    vector<int> nsr_res = nsr_index(arr, n);
    for (int i = 0; i < n; i++) {
        res = max(res, arr[i] * (nsr_res[i] - nsl_res[i] - 1));
    }
    return res;
}

int solve(int** arr, int m, int n) {
    int* mah_res = new int[n]();
    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mah_res[j] = mah_res[j] * arr[i][j] + arr[i][j];
        }
        int temp = mah(mah_res, n);
        res = max(res, temp);
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        int** arr = new int*[m];
        for (int i = 0; i < m; i++) {
            arr[i] = new int[n];
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        cout << solve(arr, m, n) << endl;
    }
    return 0;
}
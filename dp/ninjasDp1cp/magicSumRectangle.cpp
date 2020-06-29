#include <bits/stdc++.h>
using namespace std;
int kadane(vector<int> arr) {
    int max = 0, curr_max = 0;
    for (int i = 0; i < arr.size(); i++) {
        curr_max += arr[i];
        if (curr_max < 0)
            curr_max = 0;
        if (curr_max > max) {
            max = curr_max;
        }
    }
    if (max == 0) {
        max = *max_element(arr.begin(), arr.end());
    }
    return max;
}
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int r, c;
    cin >> r >> c;
    int arr[100][100];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }
    int max = INT_MIN;
    for (int left = 0; left < c - 1; left++) {
        vector<int> sum;
        for (int right = left; right < c; right++) {
            if (right == left) {
                for (int i = 0; i < r; i++) {
                    sum.push_back(arr[i][right]);
                }
                int t = kadane(sum);
                if (t > max) {
                    max = t;
                }
            } else {
                for (int i = 0; i < r; i++) {
                    sum[i] += arr[i][right];
                }
                int t = kadane(sum);
                if (t > max) {
                    max = t;
                }
            }
        }
    }
    cout << max << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
void print(vector<int> v, int start, int end) {
    for (int i = start; i <= end; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
int kadaneAlgo(vector<int> v) {
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < v.size(); i++) {
        max_ending_here = max_ending_here + v[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
void constructKadane(vector<int> v) {
    int max_so_far = INT_MIN, max_ending_here = 0;
    int start_here, end_here, start, end;
    start_here = 0, end_here = 0;
    for (int i = 0; i < v.size(); i++) {
        max_ending_here = max_ending_here + v[i];
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            start = start_here;
            end = end_here;
        }
        if (max_ending_here < 0) {
            max_ending_here = 0;
            start_here = end_here = i + 1;
        } else {
            end_here++;
        }
    }
    cout << "Actual subarray is:";
    print(v, start, end);
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        vector<int> v;
        int num;
        cin >> num;
        for (int i = 0; i < num; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        cout << "Sum is:" << kadaneAlgo(v) << endl;
        constructKadane(v);
    }
}
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
char solve(vector<char>& letters, char target) {
    int start = 0, end = letters.size();
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (letters[mid] <= target)
            start = mid + 1;
        else
            end = mid;
    }
    return letters[start % letters.size()];
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char ele;
        cin >> ele;
        vector<char> arr;
        for (int i = 0; i < n; i++) {
            char x;
            cin >> x;
            arr.push_back(x);
        }

        cout << solve(arr, ele) << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// approach 1
int findDuplicate(vector<int>& v) {
    set<int> s;
    for (int i = 0; i < v.size(); i++) {
        if (s.find(v[i]) != s.end()) {
            return v[i];
        }
        s.insert(v[i]);
    }
    return 0;
}

// approach 2 (Cycle detection)
int findDuplicate2(vector<int>& v) {
    int value, prevIndex = 0, index = 0;
    while (v[index] != -1) {
        prevIndex = index;
        index = v[index];
        v[prevIndex] = -1;
    }
    return index;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> v;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << findDuplicate2(v);
    return 0;
}
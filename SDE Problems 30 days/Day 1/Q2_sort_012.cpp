#include <bits/stdc++.h>
using namespace std;
// approach 1(sort 0s first then 2s)
void sortColors(vector<int>& v) {
    int i = 0, index = 0;
    // Pushing 0s to left
    while (i != v.size()) {
        if (v[i] == 0) {
            swap(v[index], v[i]);
            index++;
        }

        i++;
    }

    i = 0, index = 0;
    // Pushing 2s to right
    while (i != v.size()) {
        if (v[i] != 2) {
            swap(v[index], v[i]);
            index++;
        }
        i++;
    }
}

// approach 2(sort in a single loop(imp))
// just memorize it
void sortColors2(vector<int>& v) {
    int low = 0;
    int mid = 0;
    int right = v.size() - 1;
    while (mid <= right) {
        switch (v[mid]) {
            case 0:
                swap(v[low++], v[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(v[mid], v[right--]);
                break;
        }
    }
}

void printVector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sortColors2(v);
    printVector(v);
    return 0;
}
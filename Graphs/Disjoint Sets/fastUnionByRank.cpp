#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
void makeSet(int* sets, int n) {
    for (int i = 0; i < n; i++) {
        sets[i] = -1;
    }
}

int set_find(int* sets, int x) {
    if (sets[x] < 0) {
        return x;
    }
    return set_find(sets, sets[x]);
}

void set_union(int* sets, int x, int y) {
    int root1 = set_find(sets, x);
    int root2 = set_find(sets, y);
    if (root1 == root2) {
        return;
    }
    if (sets[root1] < sets[root2]) {
        sets[root1] = root2;
    } else if (sets[root1] == sets[root2]) {
        sets[root1] -= 1;
        sets[root2] = root1;
    } else {
        sets[root2] = root1;
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int* sets = new int[n];
    makeSet(sets, n);
    set_union(sets, 1, 2);
    set_union(sets, 2, 1);
    set_union(sets, 3, 4);
    for (int i = 0; i < n; i++) {
        cout << set_find(sets, i) << " " << i << endl;
    }
    cout << endl;
    set_union(sets, 3, 1);
    set_union(sets, 0, 1);
    for (int i = 0; i < n; i++) {
        cout << set_find(sets, i) << " " << i << endl;
    }
    return 0;
}
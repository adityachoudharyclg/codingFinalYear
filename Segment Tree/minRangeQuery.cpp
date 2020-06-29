#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

void buildTree(int* arr, int* tree, int start, int end, int index) {
    if (start == end) {
        tree[index] = arr[start];
        return;
    }
    int mid = start + (end - start) / 2;
    buildTree(arr, tree, start, mid, 2 * index);
    buildTree(arr, tree, mid + 1, end, 2 * index + 1);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

int query(int* arr, int* tree, int start, int end, int l, int r, int index) {
    // No  overlap
    if (start > r || end < l) {
        return INT_MAX;
    }
    // Complete overlap
    if (start >= l && end <= r) {
        return tree[index];
    }
    // Partial Overlap(general case)
    int mid = start + (end - start) / 2;
    int sma1 = query(arr, tree, start, mid, l, r, 2 * index);
    int sma2 = query(arr, tree, mid + 1, end, l, r, 2 * index + 1);
    return min(sma1, sma2);
}

int updateIndex(int* arr, int* tree, int start, int end, int index, int ele, int pos) {
    // leaf node case
    if (start == end) {
        arr[pos] = ele;
        tree[index] = ele;
        return tree[index];
    }
    // General case
    int mid = start + (end - start) / 2;
    if (mid >= pos) {
        tree[index] = min(updateIndex(arr, tree, start, mid, 2 * index, ele, pos), tree[2 * index + 1]);
    } else {
        tree[index] = min(updateIndex(arr, tree, mid + 1, end, 2 * index + 1, ele, pos), tree[2 * index]);
    }
    return tree[index];
}

void updateRange(int* arr, int* tree, int start, int end, int index, int l, int r, int ele) {
    if (start > r || end < l) {
        return;
    }

    if (start == end) {
        arr[start] += ele;
        tree[index] += ele;
        return;
    }
    int mid = start + (end - start) / 2;
    // cout << mid << endl;
    updateRange(arr, tree, start, mid, 2 * index, l, r, ele);
    updateRange(arr, tree, mid + 1, end, 2 * index + 1, l, r, ele);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

void updateLazy(int* arr, int* tree, int* lazy, int start, int end, int index, int l, int r, int ele) {
   
    // Never go down if lazy exists(sbse pehle krna zarruri hai)
    if (lazy[index] != 0) {
        tree[index] += lazy[index];
        // If not leaf node
        if (start != end) {
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }
        lazy[index] = 0;
    }

    // Out of bounds
    if (start > r || end < l) {
        return;
    }

    // Complete overlap
    if (start >= l && end <= r) {
        tree[index] += ele;
        // Lazy value to children
        if (start != end) {
            lazy[2 * index] += ele;
            lazy[2 * index + 1] += ele;
        }
        return;
    }

    // Partial overlap
    int mid = start + (end - start) / 2;
    updateLazy(arr, tree, lazy, start, mid, 2 * index, l, r, ele);
    updateLazy(arr, tree, lazy, mid + 1, end, 2 * index + 1, l, r, ele);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

int queryLazy(int* arr, int* tree, int* lazy, int start, int end, int index, int l, int r) {
    // Never go down if lazy exists
    if (lazy[index] != 0) {
        tree[index] += lazy[index];
        // If not leaf node
        if (start != end) {
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }
        lazy[index] = 0;
    }

    // Out of bounds
    if (start > r || end < l) {
        return INT_MAX;
    }

    // Complete overlap
    if (start >= l && end <= r) {
        return tree[index];
    }

    // Partial overlap
    int mid = start + (end - start) / 2;
    int ans1 = queryLazy(arr, tree, lazy, start, mid, 2 * index, l, r);
    int ans2 = queryLazy(arr, tree, lazy, mid + 1, end, 2 * index + 1, l, r);
    return min(ans1, ans2);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int* arr = new int[n]();
    int* tree = new int[4 * n + 1]();
    int* lazy = new int[4 * n + 1]();
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    buildTree(arr, tree, 0, n - 1, 1);
    int t;
    cin >> t;
    while (t--) {
        char ch;
        cin >> ch;
        if (ch == 'q') {
            int l, r;
            cin >> l >> r;
            cout << queryLazy(arr, tree, lazy, 0, n - 1, 1, l, r) << endl;
        } else if (ch == 'u') {
            int ele, pos;
            cin >> ele >> pos;
            updateIndex(arr, tree, 0, n - 1, 1, ele, pos);
        } else if (ch == 'r') {
            int ele, l, r;
            cin >> ele >> l >> r;
            updateLazy(arr, tree, lazy, 0, n - 1, 1, l, r, ele);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 4 * n; i++) {
        cout << tree[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 4 * n; i++) {
        cout << lazy[i] << " ";
    }
    return 0;
}
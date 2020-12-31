#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
void buildTree(int arr[], int start, int end, int tree[], int index) {
    if (start == end) {
        tree[index] = arr[start];
        return;
    }
    int mid = start + (end - start) / 2;
    buildTree(arr, start, mid, tree, 2 * index);
    buildTree(arr, mid + 1, end, tree, 2 * index + 1);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

int query(int tree[], int qs, int qe, int s, int e, int index) {
    // Complete overlap
    if (s >= qs && e <= qe) {
        return tree[index];
    }
    // No overlap
    if (qe < s || qs > e) {
        return INT_MAX;
    }

    // Partial overlap -call both sides and update cur node
    int mid = s + (e - s) / 2;
    int leftAns = query(tree, qs, qe, s, mid, 2 * index);
    int rightAns = query(tree, qs, qe, mid + 1, e, 2 * index + 1);
    return min(leftAns, rightAns);
}

void updateNode(int tree[], int s, int e, int i, int increment, int index) {
    // No overlap
    if (i > e || i < s) {
        return;
    }

    // Leaf node
    if (s == e) {
        tree[index] += increment;
        return;
    }

    // Left and right call
    int mid = s + (e - s) / 2;
    updateNode(tree, s, mid, i, increment, 2 * index);
    updateNode(tree, mid + 1, e, i, increment, 2 * index + 1);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}

void updateRange(int tree[], int s, int e, int l, int r, int inc, int index) {
    // No overlap
    if (r < s || l > e) {
        return;
    }

    // Leaf node
    if (s == e) {
        tree[index] += inc;
        return;
    }

    // Partial Overlap
    int mid = s + (e - s) / 2;
    updateRange(tree, s, mid, l, r, inc, 2 * index);
    updateRange(tree, mid + 1, e, l, r, inc, 2 * index + 1);
    tree[index] = min(tree[2 * index], 2 * index + 1);
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
        int tree[4 * n + 1];
        buildTree(arr, 0, n - 1, tree, 1);
        // for(int i=0;i<=4*n;i++){
        //     cout<<tree[i]<<" ";
        // }
        // cout<<endl;
        int q;
        cin >> q;
        while (q--) {
            // cout<<q<<endl;
            char ch;
            cin >> ch;
            if (ch == 'q') {
                int x, y;
                cin >> x >> y;
                cout << query(tree, x, y, 0, n - 1, 1) << " ";
            } else if (ch == 'u') {
                int i, val;
                cin >> i >> val;
                updateNode(tree, 0, n - 1, i, val, 1);
            } else if (ch == 'r') {
                int l, r, inc;
                cin >> l >> r >> inc;
                updateRange(tree, 0, n - 1, l, r, inc, 1);
            }
        }
        // while (q--) {
        //     int x, y;
        //     cin >> x >> y;
        //     cout << query(tree, x, y, 0, n - 1, 1) << " ";
        // }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class Node {
   public:
    int max_sum;
    int tot_sum;
    int prefix_sum;
    int suffix_sum;
    friend void buildtree(int *arr, Node *treeNode, int start, int end, int index);
    friend void updateTree(int *arr, Node *treeNode, int start, int end, int index, int value, int idx);
    friend Node *query(Node *treeNode, int start, int end, int index, int left, int right);
};
void buildtree(int *arr, Node *treeNode, int start, int end, int index) {
    int mid = (start + end) / 2;
    if (start == end) {
        treeNode[index].max_sum = treeNode[index].tot_sum = treeNode[index].prefix_sum = treeNode[index].suffix_sum = arr[start];
        return;
    }
    buildtree(arr, treeNode, start, mid, 2 * index);
    buildtree(arr, treeNode, mid + 1, end, 2 * index + 1);
    Node l = treeNode[2 * index];
    Node r = treeNode[2 * index + 1];
    treeNode[index].max_sum = max(l.max_sum, max(r.max_sum, max(l.tot_sum + r.prefix_sum, max(r.tot_sum + l.suffix_sum, l.suffix_sum + r.prefix_sum))));
    treeNode[index].tot_sum = l.tot_sum + r.tot_sum;
    treeNode[index].prefix_sum = max(l.prefix_sum, l.tot_sum + r.prefix_sum);
    treeNode[index].suffix_sum = max(r.suffix_sum, r.tot_sum + l.suffix_sum);
}
void updateTree(int *arr, Node *treeNode, int start, int end, int index, int value, int idx) {
    if (start == end) {
        arr[idx] = value;
        treeNode[index].max_sum = treeNode[index].tot_sum = treeNode[index].prefix_sum = treeNode[index].suffix_sum = value;
        return;
    }
    int mid = (start + end) / 2;
    if (mid >= idx) {
        updateTree(arr, treeNode, start, mid, 2 * index, value, idx);
    } else {
        updateTree(arr, treeNode, mid + 1, end, 2 * index + 1, value, idx);
    }
    Node l = treeNode[2 * index];
    Node r = treeNode[2 * index + 1];
    treeNode[index].max_sum = max(l.max_sum, max(r.max_sum, max(l.tot_sum + r.prefix_sum, max(r.tot_sum + l.suffix_sum, l.suffix_sum + r.prefix_sum))));
    treeNode[index].tot_sum = l.tot_sum + r.tot_sum;
    treeNode[index].prefix_sum = max(l.prefix_sum, l.tot_sum + r.prefix_sum);
    treeNode[index].suffix_sum = max(r.suffix_sum, r.tot_sum + l.suffix_sum);
}
Node *query(Node *treeNode, int start, int end, int index, int left, int right) {
    if (start > right || end < left) {
        return NULL;
    }
    if (start >= left && end <= right) {
        return &treeNode[index];
    } else {
        int mid = (start + end) / 2;
        Node *ans = new Node();
        Node *a = query(treeNode, start, mid, 2 * index, left, right);
        Node *b = query(treeNode, mid + 1, end, 2 * index + 1, left, right);
        if (a == NULL)
            return b;
        if (b == NULL)
            return a;
        Node l = *a;
        Node r = *b;
        ans->max_sum = max(l.max_sum, max(r.max_sum, max(l.tot_sum + r.prefix_sum, max(r.tot_sum + l.suffix_sum, l.suffix_sum + r.prefix_sum))));
        ans->tot_sum = l.tot_sum + r.tot_sum;
        ans->prefix_sum = max(l.prefix_sum, l.tot_sum + r.prefix_sum);
        ans->suffix_sum = max(r.suffix_sum, r.tot_sum + l.suffix_sum);
        return ans;
    }
}
int main() {
    int n, q;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> q;
    Node *treeNode = new Node[4 * n];
    buildtree(arr, treeNode, 0, n - 1, 1);
    while (q--) {
        int x, y;
        cin >> x >> y;
        Node *ans = query(treeNode, 0, n - 1, 1, x - 1, y - 1);
        cout << ans->max_sum << endl;
    }
}
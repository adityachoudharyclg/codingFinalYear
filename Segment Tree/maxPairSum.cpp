#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
class Node {
   public:
    int maxPairSum;
    int maxValue;
};

void buildTree(int* arr, Node* tree, int start, int end, int index) {
    if (start == end) {
        tree[index].maxPairSum = 0;
        tree[index].maxValue = arr[start];
        return;
    }
    int mid = start + (end - start) / 2;
    buildTree(arr, tree, start, mid, 2 * index);
    buildTree(arr, tree, mid + 1, end, 2 * index + 1);
    tree[index].maxPairSum = max(tree[2 * index].maxPairSum, max(tree[2 * index + 1].maxPairSum, tree[2 * index].maxValue + tree[2 * index + 1].maxValue));
    tree[index].maxValue = max(tree[2 * index].maxValue, tree[2 * index + 1].maxValue);
}

Node query(int* arr, Node* tree, int start, int end, int index, int l, int r) {
    // Out of bounds
    if (start > r || end < l) {
        Node temp;
        temp.maxPairSum = temp.maxValue = INT_MIN;
        return temp;
    }
    // Complete overlap
    if (start >= l && end <= r) {
        return tree[index];
    }
    // Partial overlap
    int mid = start + (end - start) / 2;
    // cout<<mid<<endl;
    Node ans1 = query(arr, tree, start, mid, 2 * index, l, r);
    Node ans2 = query(arr, tree, mid + 1, end, 2 * index + 1, l, r);
    Node res;
    res.maxPairSum = max(ans1.maxPairSum, max(ans2.maxPairSum, ans1.maxValue + ans2.maxValue));
    res.maxValue = max(ans1.maxValue, ans2.maxValue);
    return res;
}

void update(int* arr, Node* tree, int start, int end, int index, int ele, int pos) {
    if (start == end) {
        tree[index].maxPairSum = 0;
        tree[index].maxValue = ele;
        return;
    }
    int mid = start + (end - start) / 2;
    if (mid >= pos) {
        update(arr, tree, start, mid, 2 * index, ele, pos);
    } else {
        update(arr, tree, mid + 1, end, 2 * index + 1, ele, pos);
    }
    tree[index].maxPairSum = max(tree[2 * index].maxPairSum, max(tree[2 * index + 1].maxPairSum, tree[2 * index].maxValue + tree[2 * index + 1].maxValue));
    tree[index].maxValue = max(tree[2 * index].maxValue, tree[2 * index + 1].maxValue);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int* arr = new int[n]();
    Node* tree = new Node[4 * n + 1]();
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    buildTree(arr, tree, 0, n - 1, 1);
    int t;
    cin >> t;
    while (t--) {
        char ch;
        cin >> ch;
        if (ch == 'Q') {
            int l, r;
            cin >> l >> r;
            cout << query(arr, tree, 0, n - 1, 1, l - 1, r - 1).maxPairSum << endl;
        } else {
            int ele, pos;
            cin >> pos >> ele;
            update(arr, tree, 0, n - 1, 1, ele, pos-1);
        }
    }
    return 0;
}
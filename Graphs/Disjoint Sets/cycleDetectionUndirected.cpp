#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int set_find(int* arr, int x) {
    // cout<<"hello"<<arr[x]<<" "<<x<<endl;
    if (arr[x] < 0) {
        return x;
    }
    return set_find(arr, arr[x]);
}
void set_union(int* arr, int root1, int root2) {
    if (root1 == root2) {
        return;
    }
    if (arr[root1] < arr[root2]) {
        arr[root1] = root2;
    } else if (arr[root1] == arr[root2]) {
        arr[root1] -= 1;
        arr[root2] = root1;
    } else {
        arr[root2] = root1;
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        int* arr = new int[V]();
        for (int i = 0; i < V; i++) {
            arr[i] = -1;
        }
        int flag = 0;
        while (E--) {
            int x, y;
            cin >> x >> y;
            // cout << x << " " << y << endl;
            int root1 = set_find(arr, x);
            // cout << "Root1:" << root1 << endl;
            int root2 = set_find(arr, y);
            // cout << "Root2:" << root2 << endl;
            // cout << root1 << " " << root2 << endl;
            if (root1 != root2) {
                set_union(arr, root1, root2);
                // for (int i = 0; i < V; i++) {
                //     cout << arr[i] << " ";
                // }
                // cout << endl;
            } else {
                flag = 1;
                break;
            }
        }
        cout << flag << endl;
    }
    return 0;
}
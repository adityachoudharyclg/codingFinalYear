#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
void createBlocks(int arr[], int blocks[], int n, int rn) {
    int block_id = -1;
    for (int i = 0; i < n; i++) {
        if (i % rn == 0)
            block_id++;
        blocks[block_id] += (arr[i] % 5 == 0);
    }
    // for(int i=0;i<rn+1;i++){
    //     cout<<blocks[i]<<" ";
    // }
    // cout<<endl;
}
int query(int arr[], int blocks[], int n, int rn, int l, int r) {
    int ans = 0;
    // left part
    while (l < r && l != 0 && l % rn != 0) {
        ans += (arr[l]%5==0);
        l++;
    }
    // middle part
    while (l + rn <= r) {
        ans += blocks[l / rn];
        l += rn;
    }
    // last part
    while (l <= r) {
        ans += (arr[l] % 5 == 0);
        l++;
    }
    return ans;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m;
    cin >> m;
    while (m--) {
        int n;
        cin >> n;
        int t;
        cin >> t;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int rn = sqrt(n);
        int blocks[rn + 1];
        memset(blocks, 0, sizeof(blocks));
        createBlocks(arr, blocks, n, rn);
        while (t--) {
            int x, y;
            cin >> x >> y;
            cout << query(arr, blocks, n, rn, x-1, y-1) << " ";
        }
        cout<<endl;
    }
    return 0;
}
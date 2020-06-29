#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
void update(int ele, int index, int* BIT, int n) {
    while(index<=n){
        BIT[index]=max(BIT[index],ele);
        index+=index&(-index);
    }
}
int query(int index, int* BIT) {
    int res=0;
    while(index>0){
        res=max(res,BIT[index]);
        index-=index&(-index);
    }
    return res;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin>>n;
    int* arr = new int[n + 1]();
    int* BIT = new int[n + 1]();
    for (int i = 1; i <= n; i++) {
        cin>>arr[i];
        update(arr[i], i, BIT, n);
    }

    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        cout << query(num,BIT) << endl;
    }
    return 0;
}
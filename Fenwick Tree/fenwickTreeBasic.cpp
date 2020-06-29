#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
void update(int index, int ele, int* BIT, int n) {
    while(index<=n){
        BIT[index]+=ele;
        index+=(index&(-index));
    }
}
int query(int index, int* BIT) {
    int total=0;
    while(index>0){
        total+=BIT[index];
        index-=(index&(-index));
    }
    return total;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int* arr = new int[n + 1]();
    int* BIT = new int[n + 1]();
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        update(i, arr[i], BIT, n);
    }
    cout << "Sum of first 5 elements:" << query(5, BIT) << endl;
    cout << "Sum of elements from 2 to 6 index:" << query(6, BIT) - query(1, BIT) << endl;
    return 0;
}
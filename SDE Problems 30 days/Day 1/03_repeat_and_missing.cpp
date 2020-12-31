#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
// use elements as index
int* findTwoElement(int arr[], int n) {
    int* res = new int[2];
    for (int i = 0; i < n; i++) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else{
            res[0] = abs(arr[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0){
            res[1]=(i + 1);
            break;
        }            
    }
    return res;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    // cin>>t;
    t = 1;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int* ans = findTwoElement(arr, n);
        cout << ans[0] << " " << ans[1];
    }
    return 0;
}
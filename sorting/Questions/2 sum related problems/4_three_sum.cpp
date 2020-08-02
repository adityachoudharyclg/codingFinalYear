#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define ump unordered_map<int, int>
using namespace std;
int approach2(int arr[], int n, int target) {
    ump hashmap;
    for (int i = 0; i < n; i++) {
        hashmap[arr[i]]++;
    }
    for (int i = 0; i < n; i++) {
        int init_val = hashmap[arr[i]];
        hashmap[arr[i]]--;
        int temp = target - arr[i];
        for (int j = 0; j < n; j++) {
            int init_val = hashmap[arr[j]];
            hashmap[arr[j]]--;
            bool cond1 = (i != j);
            bool cond2 = hashmap.find(temp - arr[j]) != hashmap.end();
            bool cond3 = hashmap[temp - arr[j]] != 0;
            if (cond1 && cond2 && cond3) {
                cout << arr[i] << " " << arr[j] << " " << temp - arr[j] << endl;
                return true;
            }
            hashmap[arr[j]] = init_val;
        }
        hashmap[arr[i]] = init_val;
    }
    return false;
}
int approach1(int arr[], int n, int target) {
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        int temp = target - arr[i];
        int start = i + 1;
        int end = n - 1;
        while (start < end) {
            if ((arr[start] + arr[end]) == temp)
                return true;
            else if ((arr[start] + arr[end]) < temp)
                start++;
            else
                end--;
        }
    }
    return false;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n, target;
        cin >> n >> target;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << approach1(arr, n, target) << endl;
    }
    return 0;
}
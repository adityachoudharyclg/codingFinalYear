// we use offline programming to solve the given problem
#include <bits/stdc++.h>
using namespace std;
class event {
   public:
    int first, second, index;
};
bool compare(event a, event b) {
    return a.second < b.second;
}
void update(int index, int value, int n, int* bit) {
    while (index <= n) {
        bit[index] += value;
        index += index & (-index);
    }
}
int value(int index, int* bit) {
    int count = 0;
    while (index > 0) {
        count += bit[index];
        index -= index & (-index);
    }
    return count;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int* arr = new int[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    event* query = new event[q]();
    for (int i = 0; i < q; i++) {
        cin >> query[i].first >> query[i].second;
        query[i].index = i;
    }
    sort(query, query + q, compare);
    int* bit = new int[n + 1]();
    int* ans = new int[q]();

    int total = 0;
    int k = 0;
    int* last = new int[1000001];  // maintains ele aaya hai pehle ya nhin
    for (int i = 0; i < 1000001; i++) {
        last[i] = -1;
    }

    // bit keval mark krne ke liye use ho rha hai
    // usmein hr ith tk mein jitne unique element honge woh marked honge and repeated jo pehle aaye the woh update ke thorugh hta diye jaayenge
    for (int i = 1; i <= n; i++) {
        if (last[arr[i]] != -1) {
            // bhadi kaam krna hoga
            update(last[arr[i]], -1, n, bit);
        } else {
            total++;
        }
        update(i, 1, n, bit);
        last[arr[i]] = i;
        while (k < q && query[k].second == i) {
            ans[query[k].index] = total - value(query[k].first - 1, bit);
            k++;
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
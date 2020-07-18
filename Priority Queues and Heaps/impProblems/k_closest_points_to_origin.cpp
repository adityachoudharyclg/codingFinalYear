#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pp(i, j) pair<i, j>
#define pq_max(T) priority_queue<T, vector<T>>
using namespace std;
void solve(vector<vector<int>> arr, int n, int k) {
    pq_max(pp(int, pp(int, int))) pq;
    for (int i = 0; i < n; i++) {
        int dist = arr[i][0] * arr[i][0] + arr[i][1] * arr[i][1];
        pq.push(make_pair(dist, make_pair(arr[i][0], arr[i][1])));
        if(pq.size()>k){
            pq.pop();
        }
    }
    while(!pq.empty()){
        cout<<pq.top().second.first<<" "<<pq.top().second.second<<endl;
        pq.pop();
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++) {
            vector<int> v;
            for (int j = 0; j < 2; j++) {
                int x;
                cin >> x;
                v.push_back(x);
            }
            arr.push_back(v);
        }
        int k;
        cin >> k;
        solve(arr, n, k);
    }
    return 0;
}
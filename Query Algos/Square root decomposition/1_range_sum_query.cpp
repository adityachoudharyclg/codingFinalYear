#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
class NumArray {
    int block_size;
    int *blocks;
    vector<int> nums;

   public:
    NumArray(vector<int> &x) {
        nums = x;
        block_size = sqrt(nums.size());
        // Creating blocks arr
        blocks = new int[block_size + 1]();
        int block_id = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (i % block_size == 0) {
                block_id++;
            }
            blocks[block_id] += nums[i];
        }
    }

    void update(int i, int val) {
        // Takes O(1)
        int block_index = i / block_size;
        blocks[block_index] = blocks[block_index] + val - nums[i];
        nums[i] = val;
    }

    int sumRange(int l, int r) {
        // Take O(sqrt(n))
        int ans = 0;
        // left part
        while (l < r && l != 0 && l % block_size != 0) {
            ans += nums[l];
            l++;
        }
        // middle part
        while(l+block_size<=r){
            int block_id=l/block_size;
            ans+=blocks[block_id];
            l+=block_size;
        }
        // right size
        while(l<=r){
            ans+=nums[l];
            l++;
        }
        return ans;
    }
    void printNums() {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    NumArray rsq(nums);
    // rsq.printNums();
    int t;
    cin >> t;
    while (t--) {
        char ch;
        cin >> ch;
        if (ch == 'q') {
            // cout << "Query res" << endl;
            int i, j;
            cin >> i >> j;
            cout << rsq.sumRange(i, j) << endl;
        } else if (ch == 'u') {
            // cout << "Update res" << endl;
            int i, val;
            cin >> i >> val;
            rsq.update(i, val);
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }
        int mini = newInterval[0];
        int maxi = newInterval[1];
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            mini = min(mini, intervals[i][0]);
            maxi = max(maxi, intervals[i][1]);
            i++;
        }
        vector<int> v;
        v.push_back(mini);
        v.push_back(maxi);
        res.push_back(v);
        while (i < intervals.size()) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};
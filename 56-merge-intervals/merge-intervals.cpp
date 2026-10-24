class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
            //  [](const vector<int>& a, const vector<int>& b) {
            //      return a[0] < b[0];
            //  });

        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& ans = res.back();
            if (intervals[i][0] <= ans[1]) {
                ans[1] = max(intervals[i][1], ans[1]);
            } 
            else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
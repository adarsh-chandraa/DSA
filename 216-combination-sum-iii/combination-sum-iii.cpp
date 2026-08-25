class Solution {
public:
    void solve(int start, int k, int n, vector<vector<int>>& ans,
               vector<int>& temp, int sum) {

        if (k == 0) {
            if (sum == n)
                ans.push_back(temp);
            return;
        }

        if (sum > n)
            return;

        for (int i = start; i <= 9; i++) {
            temp.push_back(i);
            solve(i + 1, k - 1, n, ans, temp, sum + i);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, k, n, ans, temp, 0);
        return ans;
    }
};
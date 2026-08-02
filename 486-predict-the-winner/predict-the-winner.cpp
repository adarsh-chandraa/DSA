

class Solution {
public:
    

    int solve(int i, int j, vector<int>& nums,vector<vector<int>>&dp) {

        if (i == j)
            return nums[i];

        if (dp[i][j] != -1)
            return dp[i][j];

        int left = nums[i] - solve(i + 1, j, nums,dp);
        int right = nums[j] - solve(i, j - 1, nums,dp);

        return dp[i][j] = max(left, right);
    }

    bool predictTheWinner(vector<int>& nums) {

        vector<vector<int>>dp(21,vector<int>(21,-1));

        int ans = solve(0, nums.size() - 1, nums,dp) ;
        return ans >=0;
    }
};
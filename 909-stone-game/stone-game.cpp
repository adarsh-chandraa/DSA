class Solution {
public:
    int solve(int i, int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i==j) return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];
        int left = nums[i] - solve(i+1,j,nums,dp);
        int right = nums[j] - solve(i,j-1,nums,dp);
        return dp[i][j] = max(left,right);
    }
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>>dp(501,vector<int>(501,-1));
        int n = piles.size();
        int ans = solve(0,n-1,piles,dp);
        return ans>0;
    }
};
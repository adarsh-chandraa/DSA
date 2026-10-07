class Solution {
public:
    int solve(int n,int idx,vector<int>&nums,vector<int>&dp){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int inc = solve(n,idx+2,nums,dp)+nums[idx];
        int exc = solve(n,idx+1,nums,dp);
        return dp[idx] = max(inc,exc);
    }
    int rob(vector<int>& nums) {
         int n = nums.size();
         vector<int>dp(n+1,-1);
         return solve(n,0,nums,dp);
         
    }
};
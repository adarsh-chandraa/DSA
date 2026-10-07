class Solution {
public:
    int memo(int idx,vector<int>&nums,int n,vector<int>&dp){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int inc = nums[idx]+ memo(idx+2,nums,n,dp);
        int exc = memo(idx+1,nums,n,dp);
        return dp[idx] = max(inc,exc);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dp(n,-1);
        int c1 = memo(0,nums,n-1,dp);
        dp.assign(n,-1);
        int c2 = memo(1,nums,n,dp);
        return max(c1,c2);
    }
};
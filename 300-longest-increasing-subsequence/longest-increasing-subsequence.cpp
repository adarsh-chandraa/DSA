class Solution {
public:

    int solve(vector<int>&nums,int n,int curr,int prev){
    if(curr > n) return 0;
    int take =0;
    if(prev == -1 || nums[curr] > nums[prev]){
        take = 1+ solve(nums,n,curr+1,curr);
    }
    int nottake = 0+solve(nums,n,curr+1,prev);
    return max(take,nottake);
   }

    int solveMemo(vector<int>&nums,int n,int curr,int prev,vector<vector<int>>&dp){
    if(curr > n) return 0;
    if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
    int take =0;
    if(prev == -1 || nums[curr] > nums[prev]){
        take = 1+ solveMemo(nums,n,curr+1,curr,dp);
    }
    int nottake = 0+solveMemo(nums,n,curr+1,prev,dp);
    dp[curr][prev+1] =  max(take,nottake);
    return dp[curr][prev+1];
   }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size()-1;
       // return solve(nums,n,0,-1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveMemo(nums,n,0,-1,dp);
    }
};
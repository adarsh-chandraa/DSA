class Solution {
public:

    // int solve(vector<int>& nums,int idx,int jumps){
    //     int n = nums.size();
    //     if(idx >= n-1) return jumps;
    //     for(int i =1;i<=nums[idx];i++){
    //      mini = min(mini,solve(nums,idx+i,jumps+1));
    //     }
    //     return mini;
    // }

    // int solveMemo(vector<int>& nums,int idx,int jumps,vector<vector<int>>&dp){
    //     int n = nums.size();
    //     if(idx >= n-1) return jumps;
    //     if(dp[idx][jumps]!=-1) return dp[idx][jumps];
    //     int mini = INT_MAX;
    //     for(int i =1;i<=nums[idx];i++){
    //      mini = min(mini,solveMemo(nums,idx+i,jumps+1,dp));
    //     }
    //     dp[idx][jumps] = mini;
    //     return dp[idx][jumps];
    // }

    int solveTab(vector<int>& nums){
        int n = nums.size();
        vector<int>dp(n,INT_MAX);
        dp[0] = 0; // dp[i] means for reaching 0th position we required dp[i] jumps minimum
        for(int i =1;i<nums.size();i++){
           for(int j = 0;j<i;j++){
              if(j+nums[j] >= i && dp[j]!=INT_MAX) dp[i]= min(dp[i],dp[j]+1);
           }
        }
        return dp[n-1];
    }
    int jump(vector<int>& nums) {
       // return solve(nums,0,0);

        // int n = nums.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return solveMemo(nums,0,0,dp);

        return solveTab(nums);
    }
};
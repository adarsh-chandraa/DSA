class Solution {
public:
 void solve(vector<int>&nums,vector<vector<int>>&ans,int n){
    if(n >= nums.size()){
      ans.push_back(nums);
      return;
    }
    for(int i = n;i<nums.size();i++){
        swap(nums[n],nums[i]);
        solve(nums,ans,n+1);
        swap(nums[n],nums[i]);
    }
  }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(nums,ans,0);
        return ans;
   }
};
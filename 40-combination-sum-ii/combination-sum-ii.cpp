class Solution {
public:
    void solve(vector<int>& nums,int sum ,int tar,int i,vector<vector<int>>&ans,int n,vector<int>&temp){
    
        if(tar == sum){
            ans.push_back(temp);
           return;
        }
        if(sum >tar) return;

        for(int j = i;j<n;j++){
            if(j > i && nums[j] == nums[j-1])
                continue;
            sum = sum + nums[j];
            temp.push_back(nums[j]);
            solve(nums,sum,tar,j+1,ans,n,temp);
           sum = sum - nums[j];
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int tar) {
       vector<vector<int>>ans;
       int n = nums.size();
       int sum = 0;
       vector<int>temp;
       sort(nums.begin(),nums.end());
       solve(nums,sum,tar,0,ans,n,temp);
       return ans;
    }
};
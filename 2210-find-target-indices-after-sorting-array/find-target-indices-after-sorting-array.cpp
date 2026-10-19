class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(int i = 0;i<nums.size();i++){
            if(ans.size()>0 && nums[i]!= target) return ans;
            else if(nums[i]==target) ans.push_back(i);
        }
        return ans;
    }
};
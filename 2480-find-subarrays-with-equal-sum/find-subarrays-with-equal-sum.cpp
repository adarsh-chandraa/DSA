class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i = 0;i<nums.size()-1;i++){
            int sum = nums[i]+nums[i+1];
            if(mp[sum]>0) return true;
            mp[sum]++;
        }
        return false;
    }
};
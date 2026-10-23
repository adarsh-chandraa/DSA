class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int k = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=i) k = k & nums[i];
        }
        if(k == INT_MAX) return 0;
        return k;
    }
};
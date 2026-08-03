class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mini = INT_MAX;
        int mid = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>mid) return true;
            else if(nums[i]<=mini){
                mini = nums[i];
            }
             
            else mid = nums[i];
            // else if(nums[i]<mid) mid = nums[i];
            
        }
        return false;
    }
};
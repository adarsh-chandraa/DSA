class Solution {
public:
    bool check(vector<int>& nums) {
         int end = nums.size();
        int count = 0;
       
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[(i+1)%end]) count++;
        }
        if(count>1) return false ;
        return true;
    }
};
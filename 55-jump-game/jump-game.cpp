class Solution {
public:
  
    bool canJump(vector<int>& nums) {
        int n  = nums.size();
        int minidx = 0;
        for(int i =0;i<n;i++){
            if(i > minidx) return false;
            minidx = max(minidx,i+nums[i]);

        }
        return true;
    }
};
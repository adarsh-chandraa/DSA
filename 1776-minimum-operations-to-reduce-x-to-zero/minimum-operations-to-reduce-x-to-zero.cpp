class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum  = 0;
        for(auto &it:nums){
            sum += it;
        }
        if(sum < x) return -1;
        if(sum == x) return nums.size(); 
        int rem = sum-x;
        int ans = 0;
        int l = 0 ;
        int r = 0;
        int sum1 = 0;
        while(r<nums.size()){
           sum1 = sum1 + nums[r];
           while(sum1 > rem){
            sum1 = sum1 - nums[l];
            l++;
           }
           if(sum1 == rem) ans = max(ans,r-l+1);
           r++;
        }
        if(ans == 0) return -1;
        return nums.size()-ans; 
    }
};
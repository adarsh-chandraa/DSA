class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans =1;
        int incct = 1;
        int decct = 1;
        for(int i = 1; i<nums.size() ; i++){
            if(nums[i] > nums[i-1]){
                incct += 1;
            }else{
                incct = 1;
            }
            ans = max(ans,incct);
        }
        for(int i = 1 ; i<nums.size() ; i++){
            if(nums[i] < nums[i-1]){
                decct += 1;
            }else{
                decct = 1;
            }
            ans = max(ans , decct);
        }
        return ans;
    }
};
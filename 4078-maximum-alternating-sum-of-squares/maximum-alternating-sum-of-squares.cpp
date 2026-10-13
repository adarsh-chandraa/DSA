class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
       
        long long ans = 0;
        int l = 0;
        int r = nums.size()-1;
        for(int i = 0;i<nums.size();i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.rbegin(),nums.rend());
        while(l<=r){
            if(l==r) ans = ans+(nums[r]*nums[r]);
            ans = ans + (nums[l]*nums[l]) - (nums[r]*nums[r]);
            l++;
            r--;
        }
        return ans;
    }
};
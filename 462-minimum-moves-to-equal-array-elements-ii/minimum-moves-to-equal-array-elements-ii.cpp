class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int val = 0;
        if(n%2!=0) val = nums[(n-1)/2];
        else {
            int mid = n/2;
            val = nums[mid]+nums[mid-1];
            val = val/2;
        }

        int sum = 0;
        for(int it:nums){
            sum += abs(it-val);
        }
        return sum;

    }
};
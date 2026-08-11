class Solution {
public:
    int missingInteger(vector<int>& nums) {
        set<int>st;
        for(auto &it:nums){
            st.insert(it);
        }
        int l = 0;
        int r = 0;
        int prev = -1;
        int sum = 0;
        while(r<nums.size()){
            if(prev ==-1 || nums[r]-prev == 1){
                sum += nums[r];
                prev = nums[r];
            }
            else break;
            r++;
        }
        while(st.count(sum)>0){
             sum += 1;
        }
        return sum;
    }
};
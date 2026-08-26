class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>st;
        for(int i= 0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int m = 1;
        while(true){
            int val = k*m;
            if(st.find(val) == st.end()) return val;
            m++;
        }
        return -1;
    }
};
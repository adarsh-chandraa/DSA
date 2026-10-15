class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int l = 0;
        int  r= 0;
        set<int>st;
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            for(int j = i;j<nums.size();j++){
                st.insert(nums[j]);
                sum += (st.size()*st.size());
            }
            st.clear();
        }
        return sum;
    }
};
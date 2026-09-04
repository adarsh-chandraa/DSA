class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>ans;
        int maxi =  INT_MIN;

        for(auto &it:nums){
          maxi = max(maxi,it);
          ans.push_back(maxi);
        }
        int mini = INT_MAX;
        int res = -1;
        for(int i= nums.size()-1;i>=0;i--){
            mini =min(mini,nums[i]);
            if(ans[i] - mini <=k) res = i;
        }
        return res;
    }
};
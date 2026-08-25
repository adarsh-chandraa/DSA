class Solution {
public:
   void solve(int i ,vector<int>&nums,set<vector<int>>&st,vector<int>&temp){
    if(i == nums.size()){
        if(st.find(temp)==st.end()){
            st.insert(temp);
        }
        return;
    }
    temp.push_back(nums[i]);
    solve(i+1,nums,st,temp);
    temp.pop_back();
    solve(i+1,nums,st,temp);
   }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>st;
        vector<int>temp;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        solve(0,nums,st,temp);
        for(auto &it:st ){
            ans.push_back(it);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
    unordered_map<int,int>mp;
    for(int i = nums.size()-1;i>=0;i--) {
        mp[nums[i]] = i;
    }
    int n = nums.size();
    stack<int>st;
    for(int i = 0;i<nums.size();i++){
     while(!st.empty()){
        int x = st.size();
        if(st.top()>nums[i] && st.size() - 1 + (n - i) >= k){
            st.pop();

        }
        else break;
     }
     if(st.size()<k)st.push(nums[i]);
    }

       vector<int> ans(k);

        for (int i = k - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

    return  ans;
    }
};
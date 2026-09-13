class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>>mp;
        for(int i =0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        vector<int>ans;
        for(int i = 0;i<queries.size();i++){
            int v = queries[i];
            int m = nums[v];
            vector<int>&temp = mp[m];
            if(temp.size()==1){
               ans.push_back(-1);
               continue;

            }
            
            auto it = upper_bound(temp.begin(),temp.end(),v);
            int next;
            if(it == temp.end()){
                next = temp[0];
            }
            else  next = *it;

            auto it2 = lower_bound(temp.begin(), temp.end(), v);
            int prev;
            if(it2 == temp.begin()){
                prev = temp.back();
            }
            else {
                it2--;
                prev = *it2;
            }
            
            int d1 = abs(v - next);
            int d2 = abs(v - prev);

            d1 = min(d1, (int)nums.size() - d1);
            d2 = min(d2, (int)nums.size() - d2);

            ans.push_back(min(d1, d2));
        }
        return ans;
    }
};
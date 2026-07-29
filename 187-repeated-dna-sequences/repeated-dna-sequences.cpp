class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int r = 0;
        int l = 0;
        vector<string>ans;
        unordered_map<string,int>mp;
        while(r<s.size()){
         if(r-l+1==10){
            string v = s.substr(l,10);
            mp[v]++;
            if(mp[v]==2)ans.push_back(v);
            l++;
         }
         r++;
        }
        return ans;
    }
};
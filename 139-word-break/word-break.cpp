// class Solution {
// public:
//     bool solve(int idx,string &s,unordered_set<string>&st ,vector<int>&dp){
//         if(idx >=s.size()) return true;
//         if(dp[idx] != -1) return dp[idx];
//         if(st.find(s)!=st.end()) return true; 
//         for(int i=1;i<=s.size();i++){
//             string temp = s.substr(idx,i);
//             if(st.find(temp)!=st.end() && solve(idx+i,s,st,dp)) {
//                  return dp[idx] =true;
//             }
//         }
//         return dp[idx] = false ;
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
//         int n = wordDict.size();
//         vector<int>dp(301,-1);
//         unordered_set<string>st;
//         for(auto &word:wordDict) st.insert(word);
//         return solve(0,s,st,dp);
//     }
// };
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;  

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                string word = s.substr(j, i - j);
                if (dp[j] && st.find(word) != st.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

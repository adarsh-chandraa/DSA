class Solution {
public:
    void solve(int start,int end,int n,string s,vector<string>&ans){
        if(start == n && end ==n){
            ans.push_back(s);
            return;
        }
        if(start>end) solve(start,end+1,n,s+')',ans);
        if(start<n) solve(start+1,end,n,s+'(',ans);
    }
    vector<string> generateParenthesis(int n) {
        
        vector<string>ans;
        int start = 0;
        int end = 0;
        solve(start,end,n,"",ans);
       return ans;
    }
};
class Solution {
public:
    void solve(vector<string>&ans,int o,int e,int n,string s){
        if(n==o && n==e){
            cout<<s<<"\n";
            ans.push_back(s);
            return;
        }
        if(o>e)solve(ans,o,e+1,n,s+')');
        if(o<n)solve(ans,o+1,e,n,s+'(');

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int o= 0;
        int e = 0;
        solve(ans,o,e,n,"");
        return ans;
    }
};
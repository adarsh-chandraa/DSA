class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int l = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='('){
                if(l>0) ans+=s[i];
                l++;
            }
            else {
                l--;
                if(l>0) ans += s[i];
            }
        }
        return ans;
    }
};
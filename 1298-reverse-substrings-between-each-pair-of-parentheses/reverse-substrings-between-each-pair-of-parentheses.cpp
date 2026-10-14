class Solution {
public:
    string reverseParentheses(string s) {
        //co
        //octe
        //de octe le -> leetcode 
        string res ="";
        stack<int>st;
        for(auto &it:s){
            if(it=='('){
                st.push(res.size());
            }
            else if(it==')'){
                int idx = st.top();
                st.pop();
                reverse(res.begin()+idx,res.end());
            }
            else res += it;
        }
        return res;
    }
};
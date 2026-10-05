class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='(')st.push(0);
            else {
             int temp = st.top();
             st.pop();
             if(temp==0) temp = 1;
             else temp = 2*temp; 
             st.top() += temp ;
            }
            
        }
        return st.top();
    }
};
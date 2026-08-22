class Solution {
public:
#include<stack>
    int longestValidParentheses(string s) {
    //     stack<char>st;
    //     st.push(-1);
    //     int count =0;
         
    // for(int i=0;i<s.size();i++){
    //         //char ch=s[i];
    //     if(s[i]=='(')
    //    {
    //     st.push(i);
    //    }
            
    //     else{
    //             st.pop();
    //             if(st.empty())
    //             {
    //             st.push(i);
    //             }
    //             else{
    //             int l=i-st.top();
    //             count=max(count,l);
    //             }
    //         }

    // }
    // return count;
    int left=0;
    int right=0;
    int maxl=0;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch=='(') left++;
        else if(ch==')') right++;
        if(right==left) {
            int l=left*2;
            maxl=max(maxl,l);
        }
        if(right>left) left=right=0;

    }
    left=0;
    right=0;
    for(int i=s.length();i>=0;i--){
        char ch=s[i];
        if(ch=='(') left++;
        else if(ch==')') right++;
        if(right==left) {
            int m=left*2;
            maxl=max(maxl,m);
        }
        if(right<left) left=right=0;

    }
    return maxl;
    }
};
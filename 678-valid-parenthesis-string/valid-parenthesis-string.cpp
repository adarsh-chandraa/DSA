class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0; 
        
        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } 
            else if (c == ')') {
                low = max(low - 1, 0);  
                high--;
            } 
            else {  // when c is '*'
                low = max(low - 1, 0);  // treat '*' as ')'
                high++;  // treat '*' as '('
            }
             // If high becomes negative, it means we have too many closing parentheses
            if (high < 0) {
                return false;
            }
        }
         // If low == 0, it means we have a valid string since the balance of parentheses is possible
        return low == 0;

    // int star=0;
    // int l = 0;
    // int r = 0;
    // for(auto &it:s){
    //     if(it=='(')l++;
    //     else if(it==')') r++;
    //     else star++;
    // }
    // if(l==r) return true;
    // return abs(l-r)==star;
    }
};

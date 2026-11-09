class Solution {
public:
    string reverseStr(string s, int k) {
        int l = 0;
        int r = 0;
        string temp = "";
        string ans = "";

        while(r < s.size()) {
            temp += s[r];

            if(r-l+1 == 2*k) {
                reverse(temp.begin(), temp.begin()+k);
                ans += temp;
                temp = "";
                l = r+1;
            }
            r++;
        }

        if(temp != "") {
            if(temp.size() < k) {
                reverse(temp.begin(), temp.end());
            }
            else {
                reverse(temp.begin(), temp.begin()+k);
            }
            ans += temp;
        }

        return ans;
    }
};
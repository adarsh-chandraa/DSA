class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<string> st;

        int l = 0;
        int r = 0;
        int cnt = 0;
        string ans = "";
        while (r < s.size()) {

            if (s[r] == '1')
                cnt++;

            while (cnt > k) {
                if (s[l] == '1')
                    cnt--;
                l++;
            }

            if (cnt == k) {
                int v = l;

                while (v <= r && s[v] == '0') v++;   

                string temp = s.substr(v, r - v + 1);
                
                if (ans.empty() || (temp.size() < ans.size()) ||
                    (temp.size() == ans.size() && temp < ans)) {
                    ans = temp;
                }
            }
            r++;
        }
        return ans;
    }
};
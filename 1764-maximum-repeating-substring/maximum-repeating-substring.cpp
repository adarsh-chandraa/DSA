class Solution {
public:
    int maxRepeating(string sequence, string word) {

        string cur = word;
        int ans = 0;

        while (sequence.find(cur) != string::npos) {
            ans++;
            cur += word;
        }

        return ans;
    }
};
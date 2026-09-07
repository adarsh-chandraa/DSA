class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> dp;

    int solve(int i, string &s) {
        if(i == 0)
            return 1;

        if(dp[i] != -1)
            return dp[i];

        int ans = (2LL * solve(i - 1, s)) % MOD;

        int last = -1;

        // Find previous occurrence of s[i-1]
        for(int j = i - 2; j >= 0; j--) {
            if(s[j] == s[i - 1]) {
                last = j;
                break;
            }
        }

        if(last != -1) {
            ans -= solve(last, s);
            ans = (ans + MOD) % MOD;
        }

        return dp[i] = ans;
    }

    int distinctSubseqII(string s) {
        int n = s.size();

        dp.assign(n + 1, -1);

        int ans = solve(n, s);

        // Remove empty subsequence
        return (ans - 1 + MOD) % MOD;
    }
};
class Solution {
public:
    bool solve(int n, vector<int> &dp) {

        if (n == 1)
            return false;

        if (dp[n] != -1)
            return dp[n];

        for (int i = 1; i < n; i++) {

            if (n % i == 0) {

                if (!solve(n - i, dp))
                    return dp[n] = 1;
            }
        }

        return dp[n] = 0;
    }

    bool divisorGame(int n) {

        vector<int> dp(n + 1, -1);

        return solve(n, dp);
    }
};
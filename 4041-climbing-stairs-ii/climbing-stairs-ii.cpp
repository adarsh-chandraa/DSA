// class Solution {
// public:
//     int solve(int n, vector<int>& cost, vector<int>& dp) {
//         if(n < 0) return 0;
//         if(n == 0) return cost[0]+1 ;

//         if(dp[n] != -1) return dp[n];

//         int a = solve(n-1, cost, dp) + 1;
//         int b = solve(n-2, cost, dp) + 4;
//         int c = solve(n-3, cost, dp) + 9;

//         return dp[n] = cost[n] + min({a, b, c});
//     }

//     int climbStairs(int n, vector<int>& costs) {
//         vector<int> dp(n, -1);
//         return solve(n-1, costs, dp);
//     }
// };


class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, 1e9);
        dp[0] = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= 3; j++) {
                if(i-j >= 0) {
                    dp[i] = min(dp[i], dp[i-j] + costs[i-1] + j*j);
                }
            }
        }

        return dp[n];
    }
};
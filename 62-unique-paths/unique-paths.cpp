class Solution {
public:
        int solve(int i, int j, int n,int m,vector<vector<int>>&dp) {
        
        if (i >= n || j >= m ) return 0;
        if (i == n-1 && j == m-1) return 1;
        if(dp[i][j]!= -1) return dp[i][j];
       
        //if (i+1 < m && Grid[i + 1][j] != 1)
        // long long right = 
        // long long down = 0;
        //if (j + 1 < n && Grid[i][j + 1] != 1)
           // down = solve(i, j + 1, Grid);
        return dp[i][j] = solve(i + 1, j, n,m,dp)+solve(i, j + 1, n,m,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0, 0, m,n,dp);
    }
};
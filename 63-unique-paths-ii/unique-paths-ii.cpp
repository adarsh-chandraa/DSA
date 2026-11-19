class Solution {
public:
    int solve(int i, int j, vector<vector<int>>&Grid,vector<vector<int>>&dp) {
        int n = Grid.size();
        int m = Grid[0].size();
        if (i >= n || j >= m || Grid[i][j] == 1) return 0;
        if (i == n-1 && j == m-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
       
        //if (i+1 < m && Grid[i + 1][j] != 1)
        // long long right = 
        // long long down = 0;
        //if (j + 1 < n && Grid[i][j + 1] != 1)
           // down = solve(i, j + 1, Grid);
        return dp[i][j] = solve(i + 1, j, Grid,dp)+solve(i, j + 1, Grid,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>&Grid) {
        int n = Grid.size();
        int m = Grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0, 0, Grid,dp);
    }
};
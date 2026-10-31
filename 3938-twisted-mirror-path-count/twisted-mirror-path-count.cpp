class Solution {
public:
    int mod = 1e9 + 7;

    int dp[501][501][2];

    int solve(vector<vector<int>>& grid, int n, int m, int i, int j, int flag) {
        if(i<0 || i>=n || j<0 || j>=m) return 0;

        if(i==n-1 && j==m-1) return 1;

        if(dp[i][j][flag] != -1) return dp[i][j][flag];

        if(grid[i][j] == 1) {
            if(flag == 0) {
                return dp[i][j][flag] = solve(grid,n,m,i+1,j,1);
            }
            else {
                return dp[i][j][flag] = solve(grid,n,m,i,j+1,0);
            }
        }

        int right = solve(grid,n,m,i,j+1,0);
        int down = solve(grid,n,m,i+1,j,1);

        return dp[i][j][flag] = (right + down) % mod;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        memset(dp,-1,sizeof(dp));

        int ans = 0;

        ans = (ans + solve(grid,n,m,0,1,0)) % mod;
        ans = (ans + solve(grid,n,m,1,0,1)) % mod;

        return ans;
    }
};
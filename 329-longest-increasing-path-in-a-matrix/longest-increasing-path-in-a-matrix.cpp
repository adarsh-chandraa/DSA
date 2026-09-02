class Solution {
public:
    int dr[4] = {-1, 0, +1, 0};
    int dc[4] = {0, +1, 0, -1};
    bool isvalid(int nr, int nc, int n, int m) {
        return nr >= 0 && nc >= 0 && nr < n && nc < m;
    }
    int dfs(int r, int c, vector<vector<int>>& matrix, int n, int m,
            vector<vector<int>>& dp, int par) {

        if (dp[r][c] != -1)
            return dp[r][c];
        int ans = 1;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (isvalid(nr, nc, n, m) && matrix[nr][nc] > par) {
                    ans = max(ans, 1 + dfs(nr, nc, matrix, n, m, dp, matrix[nr][nc]));
                }
            }
            return dp[r][c] = ans;
        }
        int longestIncreasingPath(vector<vector<int>> & matrix) {
            int n = matrix.size();
            int m = matrix[0].size();
            int ans = -1;
            vector<vector<int>> dp(n, vector<int>(m, -1));
            for (int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix[0].size(); j++) {

                    ans = max(ans, dfs(i, j, matrix, n, m, dp, matrix[i][j]));
                }
            }
            return ans;
        }
    };
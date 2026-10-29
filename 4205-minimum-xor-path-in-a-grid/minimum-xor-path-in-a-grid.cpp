class Solution {
public:
    int ans = 1e9;
    int dr[2] = {0, +1};
    int dc[2] = {+1, 0};
    

    bool isvalid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    void dfs(vector<vector<int>>& grid, int i, int j,int n, int m, int temp,vector<vector<vector<int>>> &vis) {
        if (i == n - 1 && j == m - 1) {
            ans = min(ans, temp);
            return;
        }
        if (vis[i][j][temp] != -1) return;
        vis[i][j][temp] = 1;

        for (int k = 0; k < 2; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];

            if (isvalid(nr, nc, n, m)) {
                dfs(grid, nr, nc, n, m, temp ^ grid[nr][nc],vis);
            }
        }
    }
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mx = 0;
        for (auto &v : grid) {
            for (int x : v) mx |= x;
        }      
        vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(mx + 1, -1)));
        dfs(grid, 0, 0, n, m, grid[0][0],vis);

        return ans;
    }
};
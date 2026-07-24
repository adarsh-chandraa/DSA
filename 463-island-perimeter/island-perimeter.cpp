class Solution {
public:
   int ans = 0;
   int dr[4] = {-1,0,+1,0};
   int dc[4] = {+0,+1,+0,-1};
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis){
       vis[i][j] = 1;
       int n = grid.size();
       int m = grid[0].size();
       for(int k = 0;k<4;k++){
        int nr = i +dr[k];
        int nc = j +dc[k];
        if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] ){
            if(grid[nr][nc]) dfs(nr,nc,grid,vis);
            else ans = ans +1;

        }
        else if(nr<0 || nr>=n || nc<0 || nc>=m ) ans += 1;
       }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1)dfs(i,j,grid,vis);
            }
        }
        return ans;
    }
};
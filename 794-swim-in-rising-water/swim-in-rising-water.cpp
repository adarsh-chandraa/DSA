class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<>> q;
                       // minimum time ke hisab se sab se chota sabse upper de rha hai 

         q.push({grid[0][0],{0,0}});
         int tm = 0;
         int delr[4] ={-1,0,+1,0};
         int delc[4] = {0,+1,0,-1};
         vector<vector<int>>vis(n,vector<int>(m,0));
         while(!q.empty()){ 
            auto [t, pos] = q.top(); 
            q.pop();
            int r = pos.first;
            int c = pos.second;
           if( r== n-1 && c == m-1) return t;
           //q.pop();
           for(int i = 0;i<4;i++){
            int nrow = r +delr[i];
            int ncol = c +delc[i];
            if(nrow>=0 && nrow<n &&ncol>=0 && ncol < m && !vis[nrow][ncol]){
                q.push({max(t,grid[nrow][ncol]),{nrow,ncol}});
                vis[nrow][ncol] = 1;
            }
           }
         }
         return -1;
    }
};
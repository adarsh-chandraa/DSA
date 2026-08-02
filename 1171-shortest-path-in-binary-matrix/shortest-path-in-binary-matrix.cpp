class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
    return -1;
        int dr[8] = {-1,-1,-1,0,+1,+1,+1,0};
        int dc[8] = {-1,0,+1,+1,+1,0,-1,-1};
        dist[0][0] = 0;
        while(!q.empty()){
            int t = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            if(r==n-1 && c == n-1) return t;
           for(int i = 0;i<8;i++){
            int nr = dr[i]+r;
            int nc = dc[i]+c;
            if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0){
                if(t+1 <dist[nr][nc]){
                    dist[nr][nc] = t+ 1;
                    int newt = t+ 1;
                    if(nr == n-1 && nc == n-1) return t+1;
                    q.push({newt,{nr,nc}});
                }
            }
           }

        }
        return -1;
    }
};
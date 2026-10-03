class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>dist(n*m,1e9);
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> q;

        q.push({0,0});
        int dr[4] = {-1,0,+1,0};
        int dc[4] = {0,+1,0,-1};
        while(!q.empty()){
            auto it = q.top();
            q.pop();
            int r = it.second /m;
            int c = it.second %m;

            if(r == n-1 && c == m-1)return it.first;
            for(int i= 0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr<0 || nr>=n || nc<0 || nc>= m)continue;
                int dis = it.first + grid[nr][nc];
                int val = nr*m + nc; 
                if(dis < dist[val]){
                    dist[val] = dis;
                    q.push({dis,val});
                }
                
            } 
        }
        return dist[n*m-1];
    }
};
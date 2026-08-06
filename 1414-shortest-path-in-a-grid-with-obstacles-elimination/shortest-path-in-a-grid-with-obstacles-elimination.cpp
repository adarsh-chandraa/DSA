class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,     greater<pair<int,pair<int,int>>>>pq;
        
    
        queue<pair<pair<int,int>,pair<int,int>>>q;
        q.push({{0,k},{0,0}});

        int dr[] = {-1,0,+1,0};
        int dc[] = {+0,+1,0,-1};
       // pq.push({0,{0,0}});
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dist(n,vector<vector<int>>(m, vector<int>(k + 1,1e9)));
        dist[0][0][k]= 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            //{{cost,rem},{r,c}};
            int cost = it.first.first;
            int rem = it.first.second;
            int r= it.second.first;
            int c = it.second.second;
            if(r==n-1 && c==m-1) return cost;
            for(int i = 0;i<4;i++){
                int nr = dr[i]+r;
                int nc = dc[i]+c;
                if(nr>=0 &&nr<n && nc>=0 && nc<m){
                    if(cost>dist[nr][nc][rem])continue;
                    if(grid[nr][nc]==0 && cost + 1 <dist[nr][nc][rem]){
                        dist[nr][nc][rem] = cost+1;
                        q.push({{cost+1,rem},{nr,nc}});
                    }
                    else if(grid[nr][nc]==1 && rem>0){
                       if(dist[nr][nc][rem-1]>cost+1) {
                        dist[nr][nc][rem-1] = cost+1;
                        q.push({{cost+1,rem-1},{nr,nc}});
                       }
                    }
                }
            }
        }
        return -1;
    }
};
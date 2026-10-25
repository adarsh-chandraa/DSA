class DisjointSet{
    public:
    vector<int>par,rank,size;
    DisjointSet(int n){
        rank.resize(n+1);
        size.resize(n+1,0);
        par.resize(n+1);
        for(int i = 0;i<=n;i++) par[i] = i;
    }

    int findpar(int node){
        if(par[node]==node) return par[node];
        return par[node]=findpar(par[node]);
    }

    void unionbyrank(int u,int v){
        int ulp_u = findpar(u);
        int ulp_v = findpar(v);
        if(ulp_u == ulp_v) return ;
        if(rank[ulp_u] > rank[ulp_v]) par[ulp_v] = ulp_u;
        else if(rank[ulp_u] < rank[ulp_v]){
            par[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]) {
            par[ulp_v] = ulp_u;
            
        }
        else {
            par[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionbysize(int u,int v){
        int ulp_u = findpar(u);
        int ulp_v = findpar(v);
        if(ulp_u == ulp_v) return ;
        if(size[ulp_u] < size[ulp_v]) 
        {
            par[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        
        else {
            par[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
      int dr[4] = {-1,0,+1,0};
      int dc[4] = {0,+1,0,-1};
      bool isvalid(int i ,int j,int n,int m){
        return i>=0 && i<n && j>=0 && j<m; 
      }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int val = n*m;
        DisjointSet ds(val);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1) continue;

                for(int k = 0;k<4;k++){
                   int nr = i+dr[k];
                   int nc = j+dc[k];
                   if(isvalid(nr,nc,n,m) && grid[nr][nc]==0){
                    int val1 = i*m+j;
                    int val2 = nr*m+nc;
                      ds.unionbysize(val1,val2);
                   }
                }
            }
        }

        vector<int>vis(n*m+1,0);

        for(int i= 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1) continue;
                int temp = ds.findpar(i*m+j);
                if(i==0 || i==n-1 || j==0 || j==m-1) vis[temp] = 1;
            }
        }

        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1)continue;
                int val = i*m+j;
                if(ds.findpar(val)==val && vis[val]==0) ans++;
            }
        }
        return ans;
    }
};
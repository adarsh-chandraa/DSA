class DisjointSet{
    public:
    vector<int>par,rank,size;
     DisjointSet(int n){
      rank.resize(n+1);
      size.resize(n+1,1);
      par.resize(n+1);
      for(int i = 0;i<=n;i++) par[i]= i;
    }

    int findpar(int node){
        if(par[node]==node) return node;
        return par[node] = findpar(par[node]);
    }

    void unionbysize(int u,int v){
        int ulp_u = findpar(u);
        int ulp_v = findpar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_v]>size[ulp_u]) {
            par[ulp_u]  = ulp_v;
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
    bool isvalid(int i,int j,int n,int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n*m);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==0)continue;
                for(int k = 0;k<4;k++){
                    int nr = i+dr[k];
                    int nc = j+dc[k];
                    if(isvalid(nr,nc,n,m) && grid[nr][nc]!=0){
                        int val2 = nr*m+nc;
                        int val1 = i*m+j;
                        ds.unionbysize(val1,val2);
                    }
                }
            }
        }

        vector<long long>temp(n*m+1,0);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==0)continue;
                int val = ds.findpar(i*m+j);
                temp[val] += grid[i][j];
            }
        }
        int ans = 0;
        for(int i = 0;i<temp.size();i++){
            if(temp[i]==0)continue;
            else if(temp[i]%k==0)ans++;
        }
        return ans;
    }
};
class DisjointSet
{
    
    public:
        vector<int> parent, rank, size;
        DisjointSet(int n)
        {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            size.resize(n + 1);
            for (int i = 0; i <= n; i++)
            {
                parent[i] = i;
                size[i] = 1;
            }
    }
    int findpar(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findpar(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u= findpar(u);
        int ulp_v = findpar(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        } 
    }
    void unionBySize(int u,int v){
        int ulp_u= findpar(u);
        int ulp_v = findpar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        } 
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
     int n = 0;
     int m =0;
     for(auto &it:stones){
        n = max(n,it[0]);
        m = max(m,it[1]);
     }
     DisjointSet ds(n+m+1);
     for(auto &it:stones){
        int r = it[0];
        int c = it[1]+n+1;
        ds.unionBySize(r,c);

     }
      set<int>st;
      int cnt = 0;
      for(auto &it:stones){
        int r = it[0];
        int node = ds.findpar(r);
        if(st.find(node)==st.end()){
            cnt++;
            st.insert(node);
        }
      }
      cout<<cnt;
      return stones.size() - cnt;
    }
};
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
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        DisjointSet ds(n);
        vector<pair<int,int>>vec;
        for(int i = 0;i<nums.size();i++){
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end());
        for(int i = 1;i<nums.size();i++){
            if(vec[i].first - vec[i-1].first<= limit){
                ds.unionBySize(vec[i].second,vec[i-1].second);
            }
        }

        unordered_map<int,vector<int>>mp;
        for(auto &it:vec){
            int val = it.first;
            int pos = it.second;
            int i = ds.findpar(pos);
            mp[i].push_back(val);
        }
         for(auto &it:mp){
            sort(it.second.begin(),it.second.end());
         }

        unordered_map<int,int>v;
        vector<int>ans(nums.size());
        for(int i = 0;i<nums.size();i++){
          int root = ds.findpar(i);
          ans[i] = mp[root][v[root]];
          v[root]++;
        }
        return ans;
    }
};
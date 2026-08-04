class Solution {
public:
    int countPaths(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>>adj[n];
        for(auto &it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        vector<long long>dist(n,1e18);
        vector<int>ways(n,0);
        dist[0] = 0;
        ways[0] = 1;
        int mod = (int)(1e9 + 7);
        while(!pq.empty()){
            auto it = pq.top();
            long long wt = it.first;
            int node = it.second;
            pq.pop();
            if(wt>dist[node]) continue;
            for(auto &v:adj[node]){
                int adjnode = v.first;
                int adjwt = v.second;
                if(wt + adjwt < dist[adjnode]){
                    dist[adjnode] = wt + adjwt;
                    ways[adjnode] = ways[node];
                    pq.push({wt+adjwt,adjnode});
                } 
                else if(wt + adjwt == dist[adjnode]){ 
                    ways[adjnode] = (ways[adjnode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};
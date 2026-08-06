class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
       // int n = edges.size();
        vector<pair<int,double>>adj[n];
        for(int i = 0;i<edges.size();i++){
             adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
              adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start_node});
        vector<double>dist(n,0.0);
        dist[start_node] = 1.0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            double cost = it.first;
            int node = it.second;
            if(cost<dist[node]) continue;
            if(node == end_node) return dist[node];
            for(auto it:adj[node]){
                
                double adjwt = it.second;
                int adjnode = it.first;
                if(adjwt*cost > dist[adjnode]){
                    dist[adjnode] = cost*adjwt;
                    pq.push({cost*adjwt,adjnode});
                }
            }
        }
        return dist[n-1];
    }
};
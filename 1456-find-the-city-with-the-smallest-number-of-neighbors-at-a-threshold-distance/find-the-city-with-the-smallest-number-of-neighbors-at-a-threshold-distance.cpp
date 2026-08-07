class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int m = edges.size();
       vector<vector<int>>cost(n,vector<int>(n,1e9));
       for(int i = 0;i<n;i++)cost[i][i] = 0;

        for(int i = 0;i<edges.size();i++){
           cost[edges[i][0]][edges[i][1]] = edges[i][2]; 
           cost[edges[i][1]][edges[i][0]] = edges[i][2];
           
        }

        for(int k = 0;k<n;k++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                if(cost[i][k]==1e9 || cost[k][j]==1e9)continue;
                  cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
                    
                }
            }
        }
        int ans = n;
        int city = -1;
        for(int i = 0;i<n;i++){
            int cnt = 0;
            for(int j = 0;j<n;j++){
                if(cost[i][j]<=distanceThreshold)cnt ++;
            }
            if(cnt <= ans ) {
                ans = cnt;
                city = i;
            }
        }
        return city;
    }
};
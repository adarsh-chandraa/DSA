class Solution {
public:
    int dr[3] = {1,1,1};
    int dc[3] = {-1,0,1};

    bool isvalid(int i,int j,int n,int m){
        return i>=0 && i<n && j>=0 && j<m;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;

        vector<vector<int>>dist(n,vector<int>(m,1e9));

        for(int j = 0;j<m;j++){
            pq.push({matrix[0][j],{0,j}});
            dist[0][j] = matrix[0][j];
        }

        while(!pq.empty()){
            auto [cost,pos] = pq.top();
            auto [r,c] = pos;
            pq.pop();

            if(cost > dist[r][c]) continue;

            for(int i = 0;i<3;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];

                if(isvalid(nr,nc,n,m)){
                    int ncost = cost + matrix[nr][nc];

                    if(ncost < dist[nr][nc]){
                        pq.push({ncost,{nr,nc}});
                        dist[nr][nc] = ncost;
                    }
                }
            }
        }

        return *min_element(dist[n-1].begin(),dist[n-1].end());
    }
};
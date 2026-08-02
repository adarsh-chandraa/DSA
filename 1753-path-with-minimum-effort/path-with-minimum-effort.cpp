class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        // {diff,{row,col}}
        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;

        dist[0][0] = 0;
        pq.push({0,{0,0}});
        int dr[4] = {-1,0,+1,0};
        int dc[4] = {0,+1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int maxi = it.first;
            int r= it.second.first;
            int c = it.second.second;
            cout<<maxi<<" "<<r<<" "<<c<<"\n";
            if(r == n-1 && c == m-1) return maxi;
            //cout<<maxi<<" ";
            for(int i = 0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int diff = abs(heights[r][c] - heights[nr][nc]);
                    if(diff>= maxi ){
                     if(diff < dist[nr][nc]){
                        //cout<<diff<<" ";
                        dist[nr][nc] = diff;
                        pq.push({diff,{nr,nc}});
                     }
                      
                    } 
                    else {
                         if(maxi<dist[nr][nc]){
                        dist[nr][nc] = maxi;
                        pq.push({maxi,{nr,nc}});
                         }
                    }
                }
            }
        }
        return -1;
    }
};
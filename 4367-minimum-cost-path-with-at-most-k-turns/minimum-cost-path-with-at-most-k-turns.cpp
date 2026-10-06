//iss question ki khas baat ye hai ki dirction change aur turns toh isme agar hum agar normal distance[r][c] se krenge toh problem ye ho jaegi ki turn aur dirction ko kho denge jabki sbse important whi hai toh hum isko normal dijkstra nhi bolkar modified one bol skte hai

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        const int INF = 1e9;
        // dist[r][c][dir][turns]
        vector<vector<vector<vector<int>>>> dist(n,vector<vector<vector<int>>>(m,vector<vector<int>>(4, vector<int>(k + 1, INF))));
         
        priority_queue<
            tuple<int,int,int,int,int>,
            vector<tuple<int,int,int,int,int>>,
            greater<tuple<int,int,int,int,int>>
        > pq;

        // cost, row, col, direction, turns
        pq.push({grid[0][0], 0, 0, -1, 0});

        while(!pq.empty()) {

            auto [cost, r, c, dir, turns] = pq.top();
            pq.pop();

            if(r == n-1 && c == m-1)
                return cost;

            for(int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m)continue;
                int nt = turns;
                if(dir != -1 && dir != d) nt++;
                if(nt > k)continue;
                int newCost = cost + grid[nr][nc];
                if(newCost < dist[nr][nc][d][nt]) {
                    dist[nr][nc][d][nt] = newCost;
                    pq.push({newCost,nr,nc,d,nt });
                }
            }
        }

        return -1;
    }
};
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int maxEnergy = energy;
        vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        int startR = -1, startC = -1;
        vector<pair<int,int>> litterPositions;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if (classroom[i][j] == 'S') {
                    startR = i; startC = j;
                } else if (classroom[i][j] == 'L') {
                    litterPositions.push_back({i,j});
                }
            }
        }

        int totalLitter = litterPositions.size();
        vector<vector<int>> litterIndex(m, vector<int>(n, -1));
        for (int i=0; i<totalLitter; i++) {
            litterIndex[litterPositions[i].first][litterPositions[i].second] = i;
        }

        vector<vector<vector<int>>> visitedEnergy(m, vector<vector<int>>(n, vector<int>(1 << totalLitter, -1)));

        queue<tuple<int,int,int,int,int>> q; 
        q.push({startR, startC, energy, 0, 0});
        visitedEnergy[startR][startC][0] = energy;

        while (!q.empty()) {
            auto [r, c, e, mask, steps] = q.front();
            q.pop();

            if (mask == (1 << totalLitter) - 1) return steps;

            for (auto& d : directions) {
                int nr = r + d.first;
                int nc = c + d.second;
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                char cell = classroom[nr][nc];
                if (cell == 'X') continue;

                int ne = e - 1;
                if (ne < 0) continue;

                if (cell == 'R') {
                    ne = maxEnergy;
                }

                int nmask = mask;
                if (cell == 'L') {
                    int idx = litterIndex[nr][nc];
                    nmask = mask | (1 << idx);
                }

                if (visitedEnergy[nr][nc][nmask] >= ne) continue;

                visitedEnergy[nr][nc][nmask] = ne;
                q.push({nr, nc, ne, nmask, steps + 1});
            }
        }

        return -1;
    }
};

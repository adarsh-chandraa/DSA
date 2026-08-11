class DisjointSet {

public:
    vector<int> parent, rank, size;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);

        for(int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findpar(int node) {
        if(node == parent[node])
            return node;

        return parent[node] = findpar(parent[node]);
    }

    void unionBySize(int u, int v) {

        int ulp_u = findpar(u);
        int ulp_v = findpar(v);

        if(ulp_u == ulp_v)
            return;

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {

private:

    bool isvalid(int nr, int nc, int n, int m) {
        return nr >= 0 && nr < n && nc >= 0 && nc < m;
    }

public:

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        DisjointSet ds(n * n);

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Build DSU for all existing islands
        for(int r = 0; r < n; r++) {

            for(int c = 0; c < n; c++) {

                if(grid[r][c] == 0)
                    continue;

                for(int i = 0; i < 4; i++) {

                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(isvalid(nr, nc, n, n) && grid[nr][nc] == 1) {

                        int val1 = r * n + c;
                        int val2 = nr * n + nc;

                        if(ds.findpar(val1) != ds.findpar(val2)) {
                            ds.unionBySize(val1, val2);
                        }
                    }
                }
            }
        }

        int ans = 0;
        bool hasZero = false;

        // Try converting every 0 into 1
        for(int r = 0; r < n; r++) {

            for(int c = 0; c < n; c++) {

                if(grid[r][c] == 1)
                    continue;

                hasZero = true;

                set<int> st;

                int temp = 1; 

                for(int i = 0; i < 4; i++) {

                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(isvalid(nr, nc, n, n) && grid[nr][nc] == 1) {

                        int val = nr * n + nc;

                        int node = ds.findpar(val);

                        if(st.find(node) == st.end()) {

                            st.insert(node);

                            temp += ds.size[node];
                        }
                    }
                }

                ans = max(ans, temp);
            }
        }

        if(!hasZero)
            return n * n;

        return ans;
    }
};
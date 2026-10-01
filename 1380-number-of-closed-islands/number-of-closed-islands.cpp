class DisjointSet {

public:
    vector<int> parent, rank, size;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findpar(int node) {
        if (node == parent[node]) {
            return node;
        }

        return parent[node] = findpar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findpar(u);
        int ulp_v = findpar(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findpar(u);
        int ulp_v = findpar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
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
public:

    bool check(int r, int c, int n,int m) {
        return r == 0 || r == n - 1 || c == 0 || c == m - 1;
    }

    bool isvalid(int r, int c, int n ,int m) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }

    int closedIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        DisjointSet ds(n * m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {   
                if (grid[i][j] == 1)
                    continue;

                int dr[] = {-1, 0, +1, 0};
                int dc[] = {0, +1, 0, -1};

                for (int k = 0; k < 4; k++) {

                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if (isvalid(nr, nc, n,m) && grid[nr][nc] == 0) {

                        int val = i * m + j;
                        int val2 = nr * m + nc;

                        ds.unionBySize(val, val2);
                    }
                }
            }
        }

        vector<int> vis(n * m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1)
                    continue;

                int val = i * m + j;
                int temp = ds.findpar(val);

                if (check(i, j, n,m)) {
                    vis[temp] = 1;
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1)
                    continue;

                int val = i * m + j;

                if (ds.findpar(val) == val && vis[val] == 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};


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
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
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
        } else {
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
        int ans = 0;
        DisjointSet ds(n * n);
        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1};
        for (int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++){
            int r = i;
            int c = j;
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (grid[r][c] == 1) {
                    if (isvalid(nr, nc, n, n) && grid[nr][nc] == 1) {
                        int val1 = r * n + c;
                        int val2 = nr * n + nc;
                        int n1 = ds.findpar(val1);
                        int n2 = ds.findpar(val2);
                        if (n1 != n2)
                            ds.unionBySize(n1, n2);
                        else
                            continue;
                    }
                }
            }
        }
        }
            int h = 0;
            for (int i = 0;i<n;i++){
                for(int j = 0;j<n;j++)
             {
                int r = i;
                int c = j;
                int temp = 0;
                set<int>st;
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (grid[r][c] == 1)
                        continue;

                    else if (grid[r][c] == 0) {
                        h++;
                        if (isvalid(nr, nc, n, n) && grid[nr][nc] == 1) {

                            int val = nr * n + nc;
                            int node = ds.findpar(val);
                            if(st.find(node)==st.end()){
                            temp += ds.size[node];
                            st.insert(node);
                            }
                        }
                    }
                }
                ans = max(temp + 1, ans);
            }
            }
            if(h==0) return n*n;
            return ans;
        }
    };
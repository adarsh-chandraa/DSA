class Solution {

    int timer = 1;
    void dfs(int node, int par, int tin[], int low[], vector<vector<int>>& ans,
             vector<int>& vis, vector<int> adj[]) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for (auto& it : adj[node]) {
            if (it == par)
                continue;
            if (vis[it] == 0) {
                dfs(it, node, tin, low, ans, vis, adj);
                low[node] = min(low[it],low[node]);
                if (low[it] > tin[node])
                    ans.push_back({node, it});
            } else {
                low[node] = min(low[node], tin[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<int>adj[n];
        for (auto& it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int tin[n];
        int low[n];
        vector<int> vis(n, 0);
        vector<vector<int>> ans;
        dfs(0, -1, tin, low, ans, vis, adj);
        return ans;
    }
};
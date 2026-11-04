// class DisjointSet{
    
//     public:
//         vector<int> parent, rank, size;
//         DisjointSet(int n)
//         {
//             rank.resize(n + 1, 0);
//             parent.resize(n + 1);
//             size.resize(n + 1);
//             for (int i = 0; i <= n; i++)
//             {
//                 parent[i] = i;
//                 size[i] = 1;
//             }
//     }
//     int findpar(int node){
//         if(node==parent[node]){
//             return node;
//         }
//         return parent[node]=findpar(parent[node]);
//     }
//     void unionByRank(int u,int v){
//         int ulp_u= findpar(u);
//         int ulp_v = findpar(v);
//         if(ulp_u==ulp_v) return;
//         if(rank[ulp_u]<rank[ulp_v]){
//             parent[ulp_u]=ulp_v;
//         }
//         else if(rank[ulp_v]<rank[ulp_u]){
//             parent[ulp_v]=ulp_u;
//         }
//         else{
//             parent[ulp_v]=ulp_u;
//             rank[ulp_u]++;
//         } 
//     }
//     void unionBySize(int u,int v){
//         int ulp_u= findpar(u);
//         int ulp_v = findpar(v);
//         if(ulp_u==ulp_v) return;
//         if(size[ulp_u]<size[ulp_v]){
//             parent[ulp_u]=ulp_v;
//             size[ulp_v]+=size[ulp_u];
//         }
//         else{
//             parent[ulp_v]=ulp_u;
//             size[ulp_u]+=size[ulp_v];
//         } 
//     }
// };
// class Solution {
// public:
//     vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
//         int n = edges.size();
//         int r ,c;
//         DisjointSet ds(n);
//         for(int i = 0;i<edges.size();i++){
//           if(ds.findpar(edges[i][0])!=ds.findpar(edges[i][1])){
//             ds.unionBySize(edges[i][0],edges[i][1]);
//           }
//           else {
//             r = edges[i][0];
//             c = edges[i][1];
//           }
//         }
//         return {r,c};
//     }
// };

class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findpar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findpar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findpar(u);
        int ulp_v = findpar(v);

        if(ulp_u == ulp_v) return;

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
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> indegree(n + 1, -1);

        int first = -1, second = -1;

        for(int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if(indegree[v] != -1) {
                first = indegree[v];
                second = i;
                break;
            }

            indegree[v] = i;
        }

        DisjointSet ds(n);

        for(int i = 0; i < n; i++) {
            if(i == second) continue;

            int u = edges[i][0];
            int v = edges[i][1];

            if(ds.findpar(u) == ds.findpar(v)) {
                if(first == -1) return edges[i];
                return edges[first];
            }

            ds.unionBySize(u, v);
        }

        return edges[second];
    }
};
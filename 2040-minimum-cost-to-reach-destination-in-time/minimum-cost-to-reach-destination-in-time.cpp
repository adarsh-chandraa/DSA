// class Solution {
// public:
//     int minCost(int maxTime, vector<vector<int>>& edges,
//                 vector<int>& passingFees) {

//         int n = passingFees.size();

//         vector<pair<int,int>> adj[n];
//         for (auto &e : edges) {
//             adj[e[0]].push_back({e[1], e[2]});
//             adj[e[1]].push_back({e[0], e[2]});
//         }

//         vector<vector<int>> dist(n, vector<int>(maxTime + 1, INT_MAX));

//         priority_queue<
//             vector<int>,
//             vector<vector<int>>,
//             greater<vector<int>>
//         > pq;

//         // {cost, time, node}
//         pq.push({passingFees[0], 0, 0});
//         dist[0][0] = passingFees[0];

//         while (!pq.empty()) {

//             auto cur = pq.top();
//             pq.pop();

//             int cost = cur[0];
//             int time = cur[1];
//             int node = cur[2];

//             if (node == n - 1)
//                 return cost;

//             if (cost > dist[node][time])
//                 continue;

//             for (auto &it : adj[node]) {

//                 int nxt = it.first;
//                 int edgeTime = it.second;

//                 int newTime = time + edgeTime;
//                 if (newTime > maxTime)
//                     continue;

//                 int newCost = cost + passingFees[nxt];

//                 if (newCost < dist[nxt][newTime]) {
//                     dist[nxt][newTime] = newCost;
//                     pq.push({newCost, newTime, nxt});
//                 }
//             }
//         }

//         return -1;
//     }
// };



class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges,
                vector<int>& passingFees) {

        int n = passingFees.size();

        vector<pair<int,int>> adj[n];
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        vector<int> minTime(n, INT_MAX);
        vector<int> minCost(n, INT_MAX);

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        // {cost, time, node}
        pq.push({passingFees[0], 0, 0});

        minTime[0] = 0;
        minCost[0] = passingFees[0];

        while (!pq.empty()) {

            auto cur = pq.top();
            pq.pop();

            int cost = cur[0];
            int time = cur[1];
            int node = cur[2];

            if (node == n - 1)
                return cost;

            for (auto &it : adj[node]) {

                int nxt = it.first;
                int t = it.second;

                int newTime = time + t;
                int newCost = cost + passingFees[nxt];

                if (newTime > maxTime)
                    continue;

                if (newTime < minTime[nxt]) {
                    minTime[nxt] = newTime;
                    minCost[nxt] = newCost;
                    pq.push({newCost, newTime, nxt});
                }
                else if (newCost < minCost[nxt]) {
                    minCost[nxt] = newCost;
                    pq.push({newCost, newTime, nxt});
                }
            }
        }

        return -1;
    }
};
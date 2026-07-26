// class Solution {
// public:
//     void solve(vector<int>& nums, int k, set<int>& st) {
//         if (st.count(k)) return;

//         st.insert(k);
//         solve(nums, nums[k], st);
//     }

//     int arrayNesting(vector<int>& nums) {
//         int ans = 0;

//         for (int i = 0; i < nums.size(); i++) {
//             set<int> st;
//             solve(nums, i, st);
//             ans = max(ans, (int)st.size());
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n, 0);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            int cnt = 0;
            int cur = i;

            while (!vis[cur]) {
                vis[cur] = 1;
                cur = nums[cur];
                cnt++;
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};
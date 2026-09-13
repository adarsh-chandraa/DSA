
// class Solution {
// public:
//     int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
//         vector<pair<int,int>>ans;
//         set<pair<int,int>>st;
//         for(int i = 0;i<img1.size();i++){
//             for(int j = 0;j<img1[i].size();j++){
//                 if(img1[i][j]==1) ans.push_back({i,j});
//                 if(img2[i][j]==1) st.insert({i,j});
//             }
//         }
//         int res = 0;
//         int cnt = 0;
//         for(auto &it:ans){
//            if(st.find(it)!=st.end()) cnt++;
//         }
//         res = max(res,cnt);
//         cnt = 0;
//         for(auto &it:ans){
//             int r = it.first;
//             int c = it.second;
//             int nr = r-1;
//             int nc = c;
//            if(st.find({nr,nc})!=st.end()) cnt++;
//         }
//          res = max(res,cnt);
//         cnt = 0;
//         for(auto &it:ans){
//             int r = it.first;
//             int c = it.second;
//             int nr = r;
//             int nc = c+1;
//            if(st.find({nr,nc})!=st.end()) cnt++;
//         }
//         res = max(res,cnt);
//         cnt = 0;
//         for(auto &it:ans){
//             int r = it.first;
//             int c = it.second;
//             int nr = r+1;
//             int nc = c;
//            if(st.find({nr,nc})!=st.end()) cnt++;
//         }
//         res = max(res,cnt);
//         cnt = 0;
//         for(auto &it:ans){
//             int r = it.first;
//             int c = it.second;
//             int nr = r;
//             int nc = c-1;
//            if(st.find({nr,nc})!=st.end()) cnt++;
//         }
//         res = max(res,cnt);
//         cnt = 0;
//         return res;
//     }
// };
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1, ones2;

        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                if(img1[r][c] == 1)
                    ones1.push_back({r, c});
                if(img2[r][c] == 1)
                    ones2.push_back({r, c});
            }
        }

        unordered_map<int, int> frequency;
        int maxOverlap = 0;

        for(auto [r1, c1] : ones1){
            for(auto [r2, c2] : ones2){
                int dr = r1 - r2;
                int dc = c1 - c2;
                int key = dr * 100 + dc;
                // ulternate option, map<pair<int, int>, int> freq; 
                // pair<int, int> key = {dr, dc};
                frequency[key]++;
                maxOverlap = max(maxOverlap, frequency[key]);
            }
        }

        return maxOverlap;
    }
};
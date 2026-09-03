class Solution {
public:
   void dfs(string s,vector<string>&ans,unordered_map<string,vector<string>>&adj){
   
    while(!adj[s].empty()){
        string ns = adj[s].back();
        adj[s].pop_back();
        dfs(ns,ans,adj);
    }
     ans.push_back(s);
   }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        unordered_map<string, vector<string>> adj;
        for(int i = 0;i<tickets.size();i++){
            string s = tickets[i][0];
            string e = tickets[i][1];
            adj[s].push_back(e);
        }
       for(auto &[_,it]:adj){
        sort(it.rbegin(),it.rend());
       }
       vector<string>ans;
        dfs("JFK",ans,adj);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
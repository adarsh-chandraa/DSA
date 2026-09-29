class Solution {
public:
 bool isvalid(int r,int c,int n,int m){
    return r>=0 && r<n && c>=0 && c<m;
 }
    bool hasValidPath(vector<vector<char>>& grid) {
        queue<tuple<int,int,char>>q;
        set<tuple<int,int,int>>st;
        int n = grid.size();
        int m = grid[0].size();
         vector<vector<vector<bool>>> vis(
            n, vector<vector<bool>>(m, vector<bool>(n + m, false))
        );
        vis[0][0][1] = true;
        if(grid[0][0] == '('){
            q.push({0,0,1});
        }
        else {
            return false;
        }
        
        int dr[2] = {0,+1};
        int dc[2] = {+1,0};
      
    
        while(!q.empty()){
           auto[r,c,b] = q.front();
           q.pop();
           if(r == n-1 && c == m-1 && b == 0) return true;
            for(int i = 0;i<2;i++){
              int nr = r + dr[i];
              int nc = c + dc[i];
              int nb = b;
              if(b<0) continue;
              if(isvalid(nr,nc,n,m)){
               
                if(grid[nr][nc] == '(') nb++;
                else {
                    nb--;
                }
                 if(nb<0) continue;
               auto state = make_tuple(nr,nc,nb);
                if(!vis[nr][nc][nb]){
                    vis[nr][nc][nb] = true;
                    q.push(state);
                }
              }
            }
        }
        return false;
    }
};
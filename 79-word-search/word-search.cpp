class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    bool isvalid(int nr, int nc, int n, int m) {
        return nr >= 0 && nc >= 0 && nr < n && nc < m;
    }

    bool solve(int r, int c, vector<vector<char>>& board,
               string& word, int idx, int n, int m,
               vector<vector<int>>& vis) {

        
        if(board[r][c] != word[idx])
            return false;

    
        if(idx == word.size() - 1)
            return true;

        vis[r][c] = 1;

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(isvalid(nr, nc, n, m) && !vis[nr][nc]) {
                //cout<<board[r][c]<<"->";
                if(solve(nr, nc, board, word, idx + 1, n, m, vis)) return true;
            }
        }   
        vis[r][c] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {

                if(solve(r, c, board, word,
                         0, n, m, visited))
                    return true;
            }
        }

        return false;
    }
};
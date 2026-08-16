class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = k;
        for(int i = 0; i<k/2 ;i++){
            for(int j = 0;j<k ;j++){
                swap(grid[x+i][y+j],grid[x+k-i-1][y+j]);
                
            }
           // m = m-2;
        }
        return grid;
    }
};
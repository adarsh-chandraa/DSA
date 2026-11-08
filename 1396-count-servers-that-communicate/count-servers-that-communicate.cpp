class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        // Get dimensions of the grid
        int numRows = grid.size();
        int numCols = grid[0].size();
      
        // Arrays to store the count of servers in each row and column
        vector<int> rowServerCount(numRows, 0);
        vector<int> colServerCount(numCols, 0);
      
        // First pass: Count servers in each row and column
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                if (grid[row][col] == 1) {
                    // Increment count for this row and column
                    ++rowServerCount[row];
                    ++colServerCount[col];
                }
            }
        }
      
        // Second pass: Count servers that can communicate
        int communicatingServers = 0;
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                // A server can communicate if there's at least one other server
                // in the same row or column
                if (grid[row][col] == 1 && 
                    (rowServerCount[row] > 1 || colServerCount[col] > 1)) {
                    ++communicatingServers;
                }
            }
        }
      
        return communicatingServers;
    }
};

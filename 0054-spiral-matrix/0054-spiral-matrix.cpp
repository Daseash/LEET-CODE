class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};

        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Pre-allocate the vector with the exact size needed
        vector<int> ans(rows * cols);
        int index = 0; // Tracks where to insert the next element
        
        int stRow = 0, stCol = 0;
        int endRow = rows - 1, endCol = cols - 1;
        
        while (stRow <= endRow && stCol <= endCol) {
            // 1. Top row: left to right
            for (int i = stCol; i <= endCol; i++) {
                ans[index++] = matrix[stRow][i];
            }
            stRow++;
            
            // 2. Right column: top to bottom
            for (int i = stRow; i <= endRow; i++) {
                ans[index++] = matrix[i][endCol];
            }
            endCol--;
            
            // 3. Bottom row: right to left (if rows remain)
            if (stRow <= endRow) {
                for (int i = endCol; i >= stCol; i--) {
                    ans[index++] = matrix[endRow][i];
                }
                endRow--;
            }
            
            // 4. Left column: bottom to top (if columns remain)
            if (stCol <= endCol) {
                for (int i = endRow; i >= stRow; i--) {
                    ans[index++] = matrix[i][stCol];
                }
                stCol++;
            }
        }
        
        return ans;
    }
};
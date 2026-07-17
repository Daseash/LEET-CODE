class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.empty() || matrix[0].empty()) {
            return ans;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int stRow = 0, stCol = 0;
        int endRow = rows - 1, endCol = cols - 1;
        
        while (stRow <= endRow && stCol <= endCol) {
            // 1. Top row: traverse left to right
            for (int i = stCol; i <= endCol; i++) {
                ans.push_back(matrix[stRow][i]);
            }
            stRow++; // Move top boundary down
            
            // 2. Right column: traverse top to bottom
            for (int i = stRow; i <= endRow; i++) {
                ans.push_back(matrix[i][endCol]);
            }
            endCol--; // Move right boundary left
            
            // 3. Bottom row: traverse right to left (only if rows remain)
            if (stRow <= endRow) {
                for (int i = endCol; i >= stCol; i--) {
                    ans.push_back(matrix[endRow][i]);
                }
                endRow--; // Move bottom boundary up
            }
            
            // 4. Left column: traverse bottom to top (only if columns remain)
            if (stCol <= endCol) {
                for (int i = endRow; i >= stRow; i--) {
                    ans.push_back(matrix[i][stCol]);
                }
                stCol++; // Move left boundary right
            }
        }
        
        return ans;
    }
};
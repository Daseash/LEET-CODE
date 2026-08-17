class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<string> board(n, string(n, '.'));
        
        // Track columns and both diagonals
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n, false);
        vector<bool> diag2(2 * n, false);
        
        backtrack(0, n, board, results, cols, diag1, diag2);
        
        return results;
    }
    
private:
    void backtrack(int row, int n, vector<string>& board, vector<vector<string>>& results, 
                   vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        // Base case: If we successfully placed a queen in every row
        if (row == n) {
            results.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            // Check if placing a queen at (row, col) is safe
            // For diag2, we add `n` to `row - col` to prevent negative array indices
            if (cols[col] || diag1[row + col] || diag2[row - col + n]) {
                continue; // Not safe, try the next column
            }
            
            // 1. Place the queen
            board[row][col] = 'Q';
            cols[col] = true;
            diag1[row + col] = true;
            diag2[row - col + n] = true;
            
            // 2. Move to the next row
            backtrack(row + 1, n, board, results, cols, diag1, diag2);
            
            // 3. Backtrack (remove the queen) to explore other configurations
            board[row][col] = '.';
            cols[col] = false;
            diag1[row + col] = false;
            diag2[row - col + n] = false;
        }
    }
};
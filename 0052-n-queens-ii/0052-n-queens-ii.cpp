class Solution {
public:
    int totalNQueens(int n) {
        return backtrack(0, 0, 0, 0, n);
    }

private:
    int backtrack(int row, int cols, int diag1, int diag2, int n) {
        if (row == n) return 1;

        int count = 0;
        // Available bits for placing a queen in the current row
        int available = ~(cols | diag1 | diag2) & ((1 << n) - 1);

        while (available > 0) {
            // Isolate lowest set bit
            int position = available & -available;

            // Recurse to next row
            count += backtrack(row + 1, 
                               cols | position, 
                               (diag1 | position) << 1, 
                               (diag2 | position) >> 1, 
                               n);

            // Remove lowest set bit
            available &= available - 1;
        }

        return count;
    }
};
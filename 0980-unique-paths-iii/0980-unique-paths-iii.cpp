#include <vector>

class Solution {
public:
    int uniquePathsIII(std::vector<std::vector<int>>& grid) {
        int empty_count = 0;
        int start_x = 0, start_y = 0;
        
        // 1. Locate the start point and count empty squares
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] == 0) {
                    empty_count++;
                } else if (grid[r][c] == 1) {
                    start_x = r;
                    start_y = c;
                }
            }
        }
        
        // 2. Start DFS traversal
        return dfs(grid, start_x, start_y, empty_count);
    }
    
private:
    int dfs(std::vector<std::vector<int>>& grid, int x, int y, int zero_count) {
        // Boundary checks and obstacle/visited check
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == -1) {
            return 0;
        }
        
        // If we reach the end, check if we visited all empty squares
        if (grid[x][y] == 2) {
            return zero_count == -1 ? 1 : 0;
        }
        
        // Mark the current cell as visited
        int original_value = grid[x][y];
        grid[x][y] = -1;
        zero_count--;
        
        // Explore all 4 directions
        int total_paths = dfs(grid, x + 1, y, zero_count) +
                          dfs(grid, x - 1, y, zero_count) +
                          dfs(grid, x, y + 1, zero_count) +
                          dfs(grid, x, y - 1, zero_count);
                          
        // Backtrack: unmark the cell for other paths to explore
        grid[x][y] = original_value;
        
        return total_paths;
    }
};
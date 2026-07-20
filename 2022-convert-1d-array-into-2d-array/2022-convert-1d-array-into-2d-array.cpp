class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // Condition: Return empty array if reshaping is impossible
        if (original.size() != m * n) {
            return {};
        }

        vector<vector<int>> result;
        result.reserve(m); // Optional: optimizes memory allocation for m rows

        for (int i = 0; i < m; ++i) {
            // Slice 'n' elements for row 'i' from original
            result.push_back(vector<int>(original.begin() + i * n, original.begin() + (i + 1) * n));
        }

        return result;
    }
};
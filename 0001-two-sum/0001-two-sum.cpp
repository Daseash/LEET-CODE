#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Step 1: Pair each element with its original index: {value, original_index}
        std::vector<std::pair<int, int>> indexedNums;
        for (int i = 0; i < nums.size(); i++) {
            indexedNums.push_back({nums[i], i});
        }
        
        // Step 2: Sort the array based on values
        std::sort(indexedNums.begin(), indexedNums.end());
        
        // Step 3: Use two pointers moving inward
        int st = 0;
        int end = indexedNums.size() - 1;
        
        while (st < end) {
            int currentSum = indexedNums[st].first + indexedNums[end].first;
            
            if (currentSum == target) {
                // Return original indices stored in second element of the pair
                return {indexedNums[st].second, indexedNums[end].second};
            } 
            else if (currentSum > target) {
                end--; // Sum is too large, decrease upper bound
            } 
            else {
                st++; // Sum is too small, increase lower bound
            }
        }
        
        return {};
    }
};
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen; // Stores value -> index
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if the required complement is already in the map
            if (seen.find(complement) != seen.end()) {
                return {seen[complement], i};
            }
            
            // Store current element's value and index
            seen[nums[i]] = i;
        }
        
        return {};
    }
};
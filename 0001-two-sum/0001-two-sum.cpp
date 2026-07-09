class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;  // stores number -> index
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if the complement exists in the map
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};  // found the pair
            }
            
            // Store current number and its index
            mp[nums[i]] = i;  
        }
        
        return {};  // no solution (though problem guarantees one)
    }
};
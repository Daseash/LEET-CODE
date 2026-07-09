class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Fast I/O trick to speed up execution time
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        unordered_map<int, int> mp;
        mp.reserve(nums.size()); // Pre-allocate memory to avoid rehashing
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            if (mp.count(complement)) {
                return {mp[complement], i};
            }
            
            mp[nums[i]] = i;
        }
        
        return {};
    }
};
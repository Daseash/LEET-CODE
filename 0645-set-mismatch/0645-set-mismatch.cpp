#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());

        int duplicate = -1;
        long long actual_sum = nums[0];

        // Find the duplicate and calculate total sum of array
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                duplicate = nums[i];
            }
            actual_sum += nums[i];
        }

        // Expected sum of numbers from 1 to n: n * (n + 1) / 2
        long long expected_sum = (long long)n * (n + 1) / 2;

        // Missing number calculation
        int missing = expected_sum - (actual_sum - duplicate);

        return {duplicate, missing};
    }
};
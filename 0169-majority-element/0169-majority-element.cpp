

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int n = nums.size();

        // For-each loop through every number
        for (int num : nums) {
            // Count frequency of 'num' in the array
            int freq = std::count(nums.begin(), nums.end(), num);

            // If frequency is more than n / 2, return it
            if (freq > n / 2) {
                return num;
            }
        }

        return -1;
    }
};
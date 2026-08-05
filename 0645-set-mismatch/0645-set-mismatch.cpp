#include <vector>

class Solution {
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> count(n + 1, 0);

        for (int num : nums) {
            count[num]++;
        }

        int duplicate = -1, missing = -1;
        for (int i = 1; i <= n; i++) {
            if (count[i] == 2) duplicate = i;
            else if (count[i] == 0) missing = i;
        }

        return {duplicate, missing};
    }
};
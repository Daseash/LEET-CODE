class Solution {
public:
    int maxSum(vector<int>& nums) {
        // Array to store the maximum number seen so far for each largest digit (0-9)
        int max_val[10] = {0}; 
        int max_sum = -1;
        
        for (int num : nums) {
            int max_digit = 0;
            int temp = num;
            
            // Extract the largest digit of the current number
            while (temp > 0) {
                max_digit = max(max_digit, temp % 10);
                temp /= 10;
            }
            
            // If we've already encountered a number with the same largest digit,
            // we can form a pair. Update the global maximum sum if this pair is larger.
            if (max_val[max_digit] > 0) {
                max_sum = max(max_sum, max_val[max_digit] + num);
            }
            
            // Update the record for the largest number with this maximum digit
            max_val[max_digit] = max(max_val[max_digit], num);
        }
        
        return max_sum;
    }
};
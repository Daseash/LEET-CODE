#include <string>

class Solution {
public:
    int superpalindromesInRange(std::string left, std::string right) {
        long long L = std::stoll(left);
        long long R = std::stoll(right);
        int count = 0;
        
        // The upper bound for the square root is 10^9. 
        // A seed of up to 100000 can generate palindromes up to 9 digits long.
        int limit = 100000;
        
        // 1. Generate Odd-length palindromes (e.g. 123 -> 12321)
        for (int i = 1; i < limit; ++i) {
            long long p = createPalindrome(i, true);
            long long p_squared = p * p;
            
            if (p_squared > R) {
                break; 
            }
            if (p_squared >= L && isPalindrome(p_squared)) {
                count++;
            }
        }
        
        // 2. Generate Even-length palindromes (e.g. 123 -> 123321)
        for (int i = 1; i < limit; ++i) {
            long long p = createPalindrome(i, false);
            long long p_squared = p * p;
            
            if (p_squared > R) {
                break; 
            }
            if (p_squared >= L && isPalindrome(p_squared)) {
                count++;
            }
        }
        
        return count;
    }

private:
    // Helper to mirror a seed into a palindrome
    long long createPalindrome(long long seed, bool isOdd) {
        long long result = seed;
        if (isOdd) seed /= 10; // Skip the last digit for odd lengths
        
        while (seed > 0) {
            result = result * 10 + (seed % 10);
            seed /= 10;
        }
        return result;
    }
    
    // Helper to check if a number is a palindrome mathematically (faster than string conversion)
    bool isPalindrome(long long n) {
        long long reversed = 0;
        long long temp = n;
        
        while (temp > 0) {
            reversed = reversed * 10 + (temp % 10);
            temp /= 10;
        }
        
        return reversed == n;
    }
};
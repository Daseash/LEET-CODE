class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers cannot be palindromes (e.g., -121 becomes 121-).
        // Numbers ending in 0 cannot be palindromes unless the number is exactly 0.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int revertedNumber = 0;
        
        // Reverse the second half of the number
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        
        // When the length of the number is odd, we can get rid of the middle digit by revertingNumber / 10.
        // For example, if the input is 12321, at the end of the while loop x = 12 and revertedNumber = 123.
        return x == revertedNumber || x == revertedNumber / 10;
    }
};
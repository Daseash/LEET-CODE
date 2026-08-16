class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0;
        int maxLen = 0;

        // Lambda function to expand around the center and return the length
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            return right - left - 1;
        };

        for (int i = 0; i < s.length(); i++) {
            // Check for odd length palindromes (center is at i)
            int len1 = expandAroundCenter(i, i);
            
            // Check for even length palindromes (center is between i and i+1)
            int len2 = expandAroundCenter(i, i + 1);
            
            int len = max(len1, len2);
            
            // If we found a longer palindrome, update start index and max length
            if (len > maxLen) {
                maxLen = len;
                // Calculate the starting index of the substring
                start = i - (len - 1) / 2; 
            }
        }

        return s.substr(start, maxLen);
    }
};
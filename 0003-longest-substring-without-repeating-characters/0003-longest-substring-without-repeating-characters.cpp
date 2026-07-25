class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Use a vector to store the last seen index of each ASCII character
        // Initialize all indices to -1
        vector<int> charIndex(128, -1); 
        
        int maxLength = 0;
        int left = 0; // Left pointer of our sliding window
        
        for (int right = 0; right < s.length(); ++right) {
            // If the character was seen before and is inside our current window
            if (charIndex[s[right]] >= left) {
                // Shrink the window by moving the left pointer just past the duplicate
                left = charIndex[s[right]] + 1;
            }
            
            // Update the last seen index of the current character
            charIndex[s[right]] = right;
            
            // Calculate the current window size and update the maximum
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};
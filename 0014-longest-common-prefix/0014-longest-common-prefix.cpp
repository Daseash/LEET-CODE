class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Fast I/O trick for LeetCode
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (strs.empty()) return "";
        
        // Vertical scanning: iterate through characters of the first string
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];
            
            // Check this character against the same index in all other strings
            for (int j = 1; j < strs.size(); j++) {
                // If we reach the end of another string OR find a mismatch
                if (i == strs[j].length() || strs[j][i] != c) {
                    return strs[0].substr(0, i); // Return prefix found so far
                }
            }
        }
        
        return strs[0]; // The entire first string is the common prefix
    }
};
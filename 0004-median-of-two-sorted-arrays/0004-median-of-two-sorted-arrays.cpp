class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        // Always run binary search on the smaller array to minimize the search space
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int x = nums1.size();
        int y = nums2.size();
        
        int low = 0;
        int high = x;
        
        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;
            
            // Edge cases: if partition is at the extreme ends
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];
            
            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];
            
            // Check if we have found the correct partition
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // If the total combined length is even
                if ((x + y) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } 
                // If the total combined length is odd
                else {
                    return max(maxLeftX, maxLeftY);
                }
            } 
            // If maxLeftX is too large, move the partition left in nums1
            else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            } 
            // If maxLeftY is too large, move the partition right in nums1
            else {
                low = partitionX + 1;
            }
        }
        
        return 0.0; // Should never reach here if inputs are valid
    }
};
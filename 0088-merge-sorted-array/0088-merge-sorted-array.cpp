class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Fast I/O trick for LeetCode
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int p1 = m - 1;       // Pointer for the last valid element in nums1
        int p2 = n - 1;       // Pointer for the last element in nums2
        int p = m + n - 1;    // Pointer for the very end of nums1

        // While there are still elements in nums2 to merge
        while (p2 >= 0) {
            // If p1 is valid and nums1's element is greater, place it at the back
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } 
            // Otherwise, nums2's element is greater (or p1 is exhausted)
            else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--; // Move the placement pointer back
        }
    }
};
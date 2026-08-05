class Solution {
public:
    int maxArea(vector<int>& height) {
        int st = 0;
        int end = height.size() - 1;
        int maxWater = 0;
        
        while (st < end) {
            // Calculate current container dimensions
            int current_height = min(height[st], height[end]);
            int current_width = end - st;
            int current_area = current_height * current_width;
            
            // Keep track of maximum water
            maxWater = max(maxWater, current_area);
            
            // Move the pointer that points to the shorter line
            if (height[st] < height[end]) {
                st++;
            } else {
                end--;
            }
        }
        
        return maxWater;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0; // Good practice to handle empty arrays
        
        int leftMax[20000], rightMax[20000];
        
        leftMax[0] = height[0];
        rightMax[height.size() - 1] = height[height.size() - 1];
        
        // Fix 3: Compare against height[i] instead of height[i-1]
        for(int i = 1; i < height.size(); i++){
            leftMax[i] = max(leftMax[i-1], height[i]); 
        }
        
        // Fix 2: Loop should go down to 0 (i >= 0)
        for(int i = height.size() - 2; i >= 0; i--){
            // Fix 1 & 3: Use rightMax[i+1] and height[i]
            rightMax[i] = max(rightMax[i+1], height[i]); 
        }
        
        int trappedwater = 0;
        for(int i = 0; i < height.size(); i++){
            int water = min(leftMax[i], rightMax[i]) - height[i];
            // Since we included height[i] in our max arrays, 
            // water will never be negative, so we don't strictly need the if check.
            trappedwater += water; 
        }
        
        return trappedwater;
    }
};
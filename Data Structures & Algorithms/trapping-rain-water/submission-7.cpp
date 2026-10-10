class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int left = 0;
        int right = height.size() - 1;
        
        int left_max = 0;
        int right_max = 0;
        int water = 0;
        
        while (left < right) {
            // Process the side with the shorter bounding wall
            if (height[left] < height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left]; // Update max wall on left
                } else {
                    water += left_max - height[left]; // Water trapped above current index
                }
                left++;
            } else {
                if (height[right] >= right_max) {
                    right_max = height[right]; // Update max wall on right
                } else {
                    water += right_max - height[right]; // Water trapped above current index
                }
                right--;
            }
        }
        
        return water;
    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int midIndex = l + (r - l) / 2;
            int midVal = nums[midIndex];
            if (midVal == target) return midIndex;
            else if (midVal > target) {
                r = midIndex - 1;
            } else {
                l = midIndex + 1;
            }

        }

        return -1;
    }
};

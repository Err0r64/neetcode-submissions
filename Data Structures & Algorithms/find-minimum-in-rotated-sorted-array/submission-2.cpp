class Solution {
public:
    int findMin(vector<int> &nums) {
        // Since it's sorted but rotated, if the following number is less than the one before it means we reached the max

        // Like wise if a number following is greater, we are in the sorted section, therefore search left.

        int result = nums[0];
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            if (nums[l] < nums[r]) {
                result = min(result, nums[l]);
            }

            int mid = l + (r - l) / 2;
            int midVal = nums[mid];

            result = min(result, midVal);

            if (midVal >= nums[l]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return result;

    }
};

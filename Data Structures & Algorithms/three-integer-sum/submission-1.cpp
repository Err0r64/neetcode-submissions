class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // -4, -1, -1, 0 , 1, 2
        // 0 = nums[i] + nums[j] nums[k]
        // nums[i] = -(nums[j] + nums[k])
        vector<vector<int>> solution;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            /**
            Prevent duplicates (same value in same position twice)
                if index > 0 and nums[index] == nums[index - 1]
                If this isn't the first value in nums, and this value is equal to nums[i - 1]
                    This means it is the same value as before -> Continue
                Essentially "i" will only ever be used to point to distinct values in order to prevent duplicate use.
             */
            if (i > 0 && nums[i] == nums[i - 1]) continue; 
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) { // if sum == 0, push triplet to soltuion
                    solution.push_back({nums[i], nums[left], nums[right]});
                    // For goal case, need to update one pointer
                    left++;
                    while (nums[left] == nums[left - 1] && left < right) { // Skip if same value as before (only works on sorted nums)
                        left++;
                    }
                } else if (sum > 0) { // if sum is greater than 0, move right pointer left.
                    right--;
                } else { // if sum is less than 0, move left pointer right.
                    left++;
                }
            }


        }

        return solution;
    }
};

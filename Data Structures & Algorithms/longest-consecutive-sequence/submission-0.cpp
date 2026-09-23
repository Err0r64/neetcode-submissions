class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> sorted_nums(nums.begin(), nums.end());
        int curLongest = 0;
        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            if (sorted_nums.contains(cur - 1)) {
                continue;
            }
            int length = 1;
            while (true) {
                if (length > curLongest) {
                    curLongest = length;
                }
                if (sorted_nums.contains(cur + 1)) {
                    length++;
                    cur++;
                } else {
                    break;
                }
            }
        }
        return curLongest;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // start and end index sum first
        /**
        if sum is larger than target, move right pointer down in binary search fashion
        if sum is smaller than target, move left pointer up in binary search fashion
        **/

        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                break;
            } else if (sum > target) { // if sum is greater, move right pointer left
                right --;
            } else if (sum < target) {
                left ++;
            }
        }

        return {left + 1, right + 1};
    }
};

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
        vector<int> solution;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                solution.push_back(left + 1);
                solution.push_back(right + 1);
                break;
            } else if (sum > target) { // if sum is greater, move right pointer left
                right --;
            } else if (sum < target) {
                left ++;
            }
        }

        return solution;
    }
};

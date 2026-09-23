class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> sumMap; // Map stores [num[index], index]
        for (int i = 0; i < nums.size(); i++) {
            if (sumMap.find(nums[i]) == sumMap.end()) { // if current value in nums is not in map, add it
                sumMap[nums[i]] = i;
            }
            // if found, subtract current with target then see if difference is in map
            int diff = target - nums[i];
            if (sumMap.find(diff) != sumMap.end() && i != sumMap[diff]) {
                return {sumMap[diff], i}; // current index and index that diff key stores.
            } 
        
        }
        return {};
        
    }
};

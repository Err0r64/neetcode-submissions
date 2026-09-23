#include <unordered_set>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> unique;
        for (int i: nums) {
            if (unique.count(i)) {
                return true;
            } else {
                unique.insert(i);
            }
            
        }
        return false;
        
    }
};
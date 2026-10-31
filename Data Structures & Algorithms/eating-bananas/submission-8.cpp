class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // With the max eating rate the hours needed to eat all piles will be equal to the size of the pile

        // Therefore we use a range of possible k and perform binary search
        // With the possible range, we're going to binary search and see if each mid can eat all piles within time
        long lowestRate = numeric_limits<long>::max();

        long left = 1;
        long right = *max_element(piles.begin(), piles.end());

        while (left <= right) {
            long currentRate = left + (right - left) / 2;
            long hours = 0;
            // cout << currentRate << "\n";
            for (auto pile: piles) {
                hours += pile / currentRate + (pile % currentRate != 0);
            }
            // cout << hours << "\n";
            
            // Now binary search
            if (hours <= h) {
                lowestRate = currentRate; // No need to comparison because we know we're searching left == smaller value
                right = currentRate - 1;
            } else {
                left = currentRate + 1;
            }
        }

        return lowestRate;
    }
};

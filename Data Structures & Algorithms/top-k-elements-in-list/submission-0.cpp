class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // return a vector
        vector<int> result;

        //maxHeap to create data
        map<int, int> numMap; // num:count

        for (auto& num: nums) {
            numMap[num]++;
        }
        
        // min heap, smallest at top
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
            > minHeap;

        for (auto& entry : numMap) {
            int num = entry.first;
            int count = entry.second;

            // push all map entries to minHeap
            minHeap.push({count, num});

            // Lowest frequencies sorted to top and get popped here
            // when exceeding k.
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // move results to vector.
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;

    }
};

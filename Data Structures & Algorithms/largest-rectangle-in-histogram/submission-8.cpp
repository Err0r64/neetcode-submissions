class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> s;  // pair<height, startIndex>
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            int start = i;

            // Pop every bar taller than the current one; each one's
            // rectangle ends here, and the current bar can extend back
            // to where the last popped bar started.
            while (!s.empty() && s.top().first > heights[i]) {
                auto [h, idx] = s.top();
                s.pop();
                maxArea = max(maxArea, h * (i - idx));
                start = idx;
            }
            s.push({heights[i], start});
        }

        // Remaining bars extend to the right edge
        while (!s.empty()) {
            auto [h, idx] = s.top();
            s.pop();
            maxArea = max(maxArea, h * (n - idx));
        }
        return maxArea;
    }
};
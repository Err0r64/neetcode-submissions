class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        if (heights.empty()) return maxArea;
        stack<pair<int, int>> s;  // pair<height, startIndex>

        // First run gets any sub interval areas
        for (int i = 0; i < heights.size(); i++) {
            // Retrieve current current bar
            int curHeight = heights[i];
            int startIndex = i;

            // Process stack if any
            if (!s.empty()) {
                // Is the current bar Smaller or greater than previous?
                // If cur height is less than prev height, prev bar can't extend into current width.
                auto prevBar = s.top();
                while (!s.empty() && curHeight < prevBar.first) { 
                    // While loop handles when bar is shorter than all previous bars
                    // Compute area of previous bar/extension and make that the current bar's start
                    // index
                    int prevStartIndex = prevBar.second;
                    maxArea = max(maxArea, prevBar.first * (i - prevStartIndex));

                    s.pop();
        
                   
                    if (s.empty()) s.push({curHeight, prevStartIndex});
                    prevBar = s.top();
                    if (curHeight > prevBar.first) {
                        s.push({curHeight, prevStartIndex});
                    }
                   
                }

                if (curHeight > prevBar.first) {
                    s.push({curHeight, startIndex});
                }
         
            } else {
                s.push({curHeight, startIndex});
            }
        }

        // Any <height, startIndex> left in stack means it spans the entire histogram
        while (!s.empty()) {
            pair curBar = s.top();  // <height, startIndex>
            cout << "Height: " << curBar.first << " Start: " << curBar.second << "\n";
            maxArea = max(maxArea, (int)curBar.first * ((int)heights.size() - curBar.second));
            s.pop();
        }
        return maxArea;
    }
};

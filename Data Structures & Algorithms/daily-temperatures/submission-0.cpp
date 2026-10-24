class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Similar to using stack to track the mins, but we want to reset count every higher temperature
        stack<int> indices;
        vector<int> result;
        result.resize(temperatures.size());

        for (int i = 0; i < temperatures.size(); i++) {
            int curTemp = temperatures[i];
            while(!indices.empty() && curTemp > temperatures[indices.top()]) {
                int index = indices.top();
                result[index] = i - index;
                indices.pop();
            }

            indices.push(i);
        }

        return result;
    }
};

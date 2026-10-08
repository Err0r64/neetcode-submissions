class Solution {
public:
    int maxArea(vector<int>& heights) {
        int L = 0;
        int R = heights.size() - 1;
        int largestVolume = -1;
        while (L < R) {
            int leftWall = heights[L]; int rightWall = heights[R];
            int shortestHeight = min(leftWall, rightWall);
            int curVolume = (R - L) * shortestHeight;
            if (curVolume > largestVolume) largestVolume = curVolume;

            if (leftWall < rightWall) L++;
            else R--;
                



        }

        return largestVolume;

    }
};

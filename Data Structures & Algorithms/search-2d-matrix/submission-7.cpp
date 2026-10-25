class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Go through each row and see if the number is within the range of the bounds
        int row = 0;
        int endRow = matrix.size() - 1;
        int rowSize = matrix[0].size() - 1;
        while (row <= endRow) {
            int midRow = row + (endRow - row) / 2;
            if (matrix[midRow][0] <= target && matrix[midRow][rowSize] >= target) {
                row = midRow;
                break;
            } else if (matrix[midRow][0] < target) {
                row = midRow + 1;
            } else {
                endRow = midRow - 1;
            }
        }
        if (row > matrix.size() - 1 || row < 0) return false;
        // Then BST the row
        int l = 0;
        int r = rowSize;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int midVal = matrix[row][mid];
            if (midVal == target) {
                return true;
            } else if (midVal < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return false;
        
    }
};

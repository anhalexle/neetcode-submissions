class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int maxCol = matrix[row].size() - 1;
        while (row < matrix.size())
        {
            if (target > matrix[row][maxCol])
            {
                row++;
                continue;
            }
            int left = 0;
            int right = maxCol;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (matrix[row][mid] == target)
                    return true;
                if (matrix[row][mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            row++;
        }
        return false;
    }
};

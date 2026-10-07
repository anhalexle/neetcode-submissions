class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> mem(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        return dp(0, 0, obstacleGrid, mem);
    }
private:
    int dp(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& mem)
    {
        if (i >= obstacleGrid.size() || j >= obstacleGrid[0].size() || obstacleGrid[i][j] == 1 ) return 0;
        if (i == obstacleGrid.size() - 1 && j == obstacleGrid[0].size() - 1) return 1;
        if (mem[i][j] != -1) return mem[i][j];
        mem[i][j] = dp(i + 1, j, obstacleGrid, mem) + dp(i, j + 1, obstacleGrid, mem);
        return mem[i][j];
    }
};
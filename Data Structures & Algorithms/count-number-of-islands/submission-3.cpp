class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows= grid.size();
        int cols = grid[0].size();
        // vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int islands = 0;
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (grid[r][c] == '1')
                {
                    ++islands;
                    dfs(r, c, grid);
                }
            }
        }
        return islands;
        // T: O(r*c)
        // S: O(r*c)
    }
private:
    void dfs(int row, int col, vector<vector<char>>& grid)
    {
        // Improve to remove visited
        grid[row][col] = '0';
        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (auto& direction : directions)
        {
            int updatedRow = row + direction[0];
            int updatedCol = col + direction[1];
            if ((updatedRow >= 0 && updatedRow < grid.size())
            && (updatedCol >= 0 && updatedCol < grid[0].size())
            && grid[updatedRow][updatedCol] == '1')
                dfs(updatedRow, updatedCol, grid);
        }
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rols = grid.size();
        int cols = grid[0].size();
        set<pair<int, int>>visited; // pair: rol,col
        int island = 0;
        for (int rol = 0; rol < rols; rol++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[rol][col] == '1' && visited.count({rol, col}) == 0)
                {
                    island++;
                    bfs(rol,col, grid, visited);
                }
            }
        }
        return island;
    }
private:
    void bfs (int rol, int col, vector<vector<char>>&grid, set<pair<int,int>>&visited)
    {
        stack<pair<int,int>> myStack;
        myStack.push({rol,col});

        while(!myStack.empty())
        {
            auto topVal = myStack.top();
            myStack.pop();
            int curRow = topVal.first;
            int curCol = topVal.second;
            // create directions
            vector<pair<int,int>> directions = {{-1, 0}/*go up*/, {0, 1}/*go right*/, {1, 0} /*go down*/, {0, -1} /*go left*/};

            for (auto direction : directions)
            {
                int updatedRow = curRow + direction.first;
                int updatedColumn = curCol + direction.second;
                if ((0 <= updatedRow) && (updatedRow < grid.size()) && (updatedColumn >= 0) && (updatedColumn < grid[0].size())
                    && (grid[updatedRow][updatedColumn] == '1') && visited.count({updatedRow, updatedColumn}) == 0)
                {
                    myStack.push({updatedRow, updatedColumn});
                    visited.insert({updatedRow, updatedColumn});
                }
            }
        }
    }
};

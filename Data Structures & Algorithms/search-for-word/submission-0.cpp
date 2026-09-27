class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (dfs(board, word, row, col, 0, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
private:
bool dfs(vector<vector<char>>&board, string word, int row, int col, int index, vector<vector<bool>>& visited)
{
    if (index == word.length()) return true; // match case

    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()
        || board[row][col] != word[index] || (visited[row][col] == true)) // outbound, character didn't match word[i], already visited path
        return false;
    
    visited[row][col] = true;
    bool res = dfs(board, word, row - 1, col, index + 1, visited) ||
                dfs(board, word, row, col + 1, index + 1, visited) ||
                dfs(board, word, row + 1, col, index + 1, visited) ||
                dfs(board, word, row, col -1, index + 1, visited);
    visited[row][col] = false;
    return res;
}
};

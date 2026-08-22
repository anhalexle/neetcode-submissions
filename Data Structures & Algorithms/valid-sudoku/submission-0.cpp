class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        
        
        for (auto nums: board)
        {
            set<char> row;
            for (auto num: nums)
            {
                if (num != '.')
                {
                    if (row.find(num) != row.end())
                        return false;
                    row.insert(num);
                }
            }
        }
        for (int i = 0; i <= 8; i++)
        {
            set<char> col;
            for (int j = 0; j <=8 ; j++)
            {
                if (board[j][i] != '.')
                {
                    if (col.find(board[j][i]) != col.end())
                        return false;
                    col.insert(board[j][i]);
                }
            }
        }

        for (int square = 0; square < 9; square++)
        {
            set<char> mySquare;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    int subRow = (square/3)*3 + i;
                    int subCol = (square%3)*3 + j;
                    if (board[subRow][subCol] != '.')
                    {
                        if (mySquare.find(board[subRow][subCol]) != mySquare.end())
                            return false;
                        mySquare.insert(board[subRow][subCol]);
                    }
                }
            }
        }
        return true;
    }
};

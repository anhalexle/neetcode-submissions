class NumMatrix {
public:
    vector<vector<int>> sumMatrix;
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size() + 1;      // number of matrix rows + 1
    int cols = matrix[0].size() + 1;   // number of matrix cols + 1
        sumMatrix.assign(rows, vector<int>(cols, 0));

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                sumMatrix[i][j] = sumMatrix[i - 1][j]
                                 + sumMatrix[i][j - 1]
                                 - sumMatrix[i - 1][j - 1]
                                 + matrix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++;
        return sumMatrix[row2][col2]
             - sumMatrix[row1 - 1][col2]
             - sumMatrix[row2][col1 - 1]
             + sumMatrix[row1 - 1][col1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
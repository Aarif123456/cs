typedef vector<int> vi;
typedef vector<vi> vvi;
class NumMatrix {
public:
    /**
     * Idea: calculate grid sum from a[0][0] to a[i][j]
     * we can use a[i][j-1] - to get the rows above 
     * a[i-1][j-1] for the column to the left 
     * and subtract a[i-1][j-1] to remove the area we added twice
     * */
    vvi matrixSums;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        matrixSums = vvi(m+1, vi(n+1, 0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                matrixSums[i][j] = matrix[i-1][j-1] + matrixSums[i-1][j] 
                                    + matrixSums[i][j-1] - matrixSums[i-1][j-1];
            }
        }

    }
    
    constexpr int sumRegion(int row1, int col1, int row2, int col2) {
        /* Make end exclusive */
        row2++; col2++;
        return matrixSums[row2][col2] - matrixSums[row1][col2] 
                - matrixSums[row2][col1] + matrixSums[row1][col1];
    }
};


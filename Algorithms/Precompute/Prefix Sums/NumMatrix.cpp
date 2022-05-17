typedef vector<int> vi;
typedef vector<vi> vvi;
class NumMatrix {
public:
    vvi matrixRowSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        matrixRowSum = vvi(m, vi(n+1, 0));
        /** we store prefix sum till that point not counting that point 
         * so a[0] will always be 0
         */
        for(int x = 0; x < m; x++){
            std::partial_sum(matrix[x].begin(), matrix[x].end(), matrixRowSum[x].begin()+1);
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        /* make row and end exclusive */
        row2++; col2++;
        int sum = 0;
        for(int x = row1; x < row2; x++){
            sum +=  matrixRowSum[x][col2]  - matrixRowSum[x][col1];
        }

        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
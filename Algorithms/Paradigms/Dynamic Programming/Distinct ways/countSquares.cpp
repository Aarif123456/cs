typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vvi memo(m, vi(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int up = i ? memo[i-1][j] : 0;
                int left = j ? memo[i][j-1] : 0;
                int topLeft = i && j ? memo[i-1][j-1] : 0;
                if(matrix[i][j]) memo[i][j] = std::min({up, left, topLeft}) + 1;
            }
        }

        int sum = 0;
        for(auto &row : memo){
            for(auto &x : row){
                // cout << x << ",";
                sum += x;
            }
            // cout << endl;
        }

        return sum;
    }
};
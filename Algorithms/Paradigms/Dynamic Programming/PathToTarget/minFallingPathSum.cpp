typedef vector<int> vi; 
typedef vector<vi> vvi; 
/* For loop excluding end*/
#define FOR(i, b, c) for (int(i) = (b); (i) < (c); (i)++) 
/* For loop going till end*/
#define FORL(i, b, c) for (int(i) = (b); (i) <= (c); (i)++) 
/* For loop backward */
#define FORR(i, b, c) for (int(i) = (b); (i) >= (c); --(i))  
/* Traverse collection */
#define TRAV(a, b) for (auto&(a) : (b)) 
/* Quick for loop */
#define REP(i, rows) FOR(i, 0, rows)
/* general shortcut */
#define ALL(v) v.begin(), v.end() 
#define SIZE(v) static_cast<int>(v.size()) 

/* Practice: pattern Minimum (Maximum) Path to Reach a Target 
* Approach: Choose minimum (maximum) path among all possible paths
* before the current state, then add value for the current state.
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = SIZE(matrix);
        if(n == 1) return matrix[0][0];
        vvi dp(2, vi(n, 0));
        int curRow = 0, prevRow;
        REP(i, n){
            prevRow = curRow;
            curRow = (curRow + 1) % 2;
            dp[curRow][0] = matrix[i][0] + min(dp[prevRow][0], dp[prevRow][1]);
            FOR(j, 1, n){
                auto right = INT_MAX;
                if(j <n-1) right = dp[prevRow][j+1];
                dp[curRow][j] = matrix[i][j] + min(min(dp[prevRow][j], dp[prevRow][j-1]), right);
            }
        }
        auto absMin = INT_MAX;
        TRAV(num, dp[curRow]){
            absMin = min(absMin, num);
        }
        return absMin;
    }
};
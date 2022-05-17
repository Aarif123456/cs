typedef vector<int> vi; 
typedef vector<vi> vvi; 
/* For loop excluding end*/
#define FOR(i, b, c) for (int(i) = (b); (i) < (c); (i)++) 
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
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        /* At each point we can ask which gives us the least */
        auto rows=SIZE(grid) , cols=SIZE(grid[0]);
        /* Copy over original */
        vi dp(grid[0].begin(), grid[0].end());
        /* Handle first row */
        FOR(j, 1, cols){
            dp[j] += dp[j-1];
        }

        FOR(i, 1, rows){
            /* Only path to first element in row is form the above row
            * Like, it can't be from the left cause there its 
            * the first element in the row
            */
            dp[0] += grid[i][0];
            FOR(j, 1, cols){
                /* Either use above cell or cell to the left*/
                dp[j] = grid[i][j] + min(dp[j-1], dp[j]);
            }
        }
        return dp[cols-1];
    }
};
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
    int minCostClimbingStairs(vector<int>& cost) {
        int n = SIZE(cost); 
        if(n < 2) return 0;
        vi dp(ALL(cost));
        FOR(i, 2, n){
            dp[i] += min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
};
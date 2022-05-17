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
/* Practice: Given a target find a number of distinct ways to 
* reach the target.
* Approach: Sum all possible ways to reach the current state.
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vi dp(n, 1);
        FOR(i, 1, m){
            FOR(j, 1, n){
                dp[j]+=dp[j-1];
            }
        }
        return dp[n-1];
    }
};
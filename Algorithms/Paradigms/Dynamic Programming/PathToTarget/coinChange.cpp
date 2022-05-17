typedef vector<int> vi; 
typedef vector<vi> vvi; 
/* For loop excluding end*/
#define FOR(i, b, c) for (int(i) = (b); (i) < (c); (i)++) 
/* For loop going till end*/
#define FORL(i, b, c) for (int(i) = (b); (i) <= (c); (i)++) 
/* For loop backward */
#define FORR(i, b, c) for (int(i) = (b); (i) >= (c); --(i)) 
/* For loop with a multiple */
#define FORM(i, b, c, m) for (int(i) = (b); (i) <= (c); (i)+=(m)) 
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
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        if(coins.empty()) return -1;
        auto n = SIZE(coins);
        auto na = amount+1;
        vi dp(amount+1, na);
        dp[0] = 0;

        TRAV(coin, coins){ 
            FORL(i, coin, amount){
                /* Either use the coin or use previous value */
                if(dp[i-coin] != na) 
                    dp[i] = min(1+dp[i-coin], dp[i]);
            }
        }
        return dp[amount] == na ? -1: dp[amount];
    }
};
typedef long long ll; 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<ll> vl; 
typedef vector<vl> vvl; 
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
#define MODULO 1000000007L

class Solution {
public:
    const static ll addWithModulo(const ll &a, const ll &b ){
        return (a + b) % MODULO;
    }
    int numRollsToTarget(int dice, int faces, int target) {
        vvl dp(2, vl(target+1, 0));
        int curRow = 0, prevRow;
        dp[curRow][0] = 1;
        REP(die, dice){
            prevRow = curRow;
            curRow = (curRow + 1) % 2;
            FORL(t, 1, target){
                auto start = dp[prevRow].begin()+(t-min(t, faces));
                auto end = dp[prevRow].begin()+(t);
                dp[curRow][t] = accumulate(start, end, 0L, addWithModulo);
            }
            dp[curRow][0] = 0;
        }  
        return dp[curRow][target];
    }
};
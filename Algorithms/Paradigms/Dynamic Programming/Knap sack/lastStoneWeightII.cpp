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
#define REP(i, n) FOR(i, 0, n) 
/* general shortcut */
#define ALL(v) v.begin(), v.end() 
#define SIZE(v) static_cast<int>(v.size()) 
#define SORT(v) sort(ALL(v)) 
#define REVERSE(v) reverse(ALL(v)) 

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        /*Problem is special version of knapsack problem where our weight is half the sum */
        auto sum = accumulate(stones.begin(), stones.end(), 0);
        int target = ceil(double(sum)/2.0);
        int n = SIZE(stones);
        vi dp(target+1, 0);
        FORL(i, 1, n){
            FORR(c, target, stones[i-1]){
               dp[c] = max(dp[c], stones[i-1] + dp[c-stones[i-1]]);
            }
        }
        auto otherNum = floor(double(sum)/2.0)+(target- dp[target]);
        return abs(dp[target]- otherNum) ;
    }
};
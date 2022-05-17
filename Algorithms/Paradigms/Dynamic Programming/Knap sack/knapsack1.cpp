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
    /* Special variation of knapsack problem where our weight is our value */
    /* This is a super straightforward implementation of the bottom-up DP solution based on grokking*/
    int backPack(int capacity, vector<int> &A) {
        if(A.empty()) return 0;
        int n = SIZE(A);
        /* DP array with i for our index and value and the vector 
        * holding the max value with each capacity*/
        vvi dp(n, vi(capacity+1, 0));
        /* No capacity means no value - This is redundant so doing for clarity */
        REP(i, n){
            dp[i][0] = 0;
        }
        /* With one weight we will take it if it is within our capacity
        * We have a separate loop because we will be using the previous value
        * in the main loop.
        */
        FORL(c, 1, capacity){
            if(A[0] <=c){
                dp[0][c] = A[0]; 
            }
        }
        /* Go through each weight */
        FOR(i, 1, n){
            FORL(c, 1, capacity){
                /* Explicitly define our cases*/
                int includeItem = 0, excludeItem=0;
                /* Include item if within capacity */
                if(A[i] <= c){
                    includeItem = A[i] + dp[i-1][c-A[i]];
                }
                excludeItem = dp[i-1][c];
                // store max 
                dp[i][c] = max(includeItem, excludeItem);
            }
        }

        return dp[n-1][capacity];
    }
};
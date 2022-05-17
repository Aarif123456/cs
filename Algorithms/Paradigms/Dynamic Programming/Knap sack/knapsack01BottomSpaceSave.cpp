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
    /* Try to do bottom up without a 2D array - use only one row  */
    /* NOT GOING TO COMPLETE BUT BASICALLY WE TRY TO TRACK THE LAST ROW
    * WE CAN JUST USE i%2 - an alternate which row we use */
   /* TO IMPROVE TO OUR FINAL VERSION WE MUST REALIZE THAT TO DO IN ON ARRAY WE NEED 
   TO MAKE SURE WE DON'T OVERRIDE THE PREVIOUS DP[C-WEIGHT[I]] VALUE - SOWE GO IN THE RVERSE ORDER*/
    int backPack(int capacity, vector<int> &A) {
        if(A.empty()) return 0;
        int n = SIZE(A);
        /* We try to do it with just the capacity cause we only need the last row */
        vi dp(capacity+1, 0);
        vi *lastRow;
        lastRow = &dp;
        /* Handle the first Row */
        REP(c, capacity+1){
            if(c <= A[0]) lastRow->at(c) = A[0];
        }
        FORL(i, 1, n){
            dp = vi(capacity+1, 0);
            REP(c, capacity+1){
                auto includeItem=0, excludeItem=0;
                if(A[i] <= c){
                    includeItem = A[i] + lastRow->at(c-A[i]);
                }
                excludeItem = lastRow->at(c);
                dp[c] = max(includeItem, excludeItem);
            }
            lastRow = &dp;
        }
        return lastRow->at(capacity);
    }
};
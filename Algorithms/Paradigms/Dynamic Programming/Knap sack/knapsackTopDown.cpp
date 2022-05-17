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
    /* This is a super straightforward implementation of the top-down DP solution based on grokking*/
    int backpackRecursive(int capacity, vi& A, vvi& dp, int cur=0){
        /*Base case when our capacity is 0 or our current index is past the last element*/
        if(capacity == 0 || A.begin()+cur == A.end()) return 0;
        if(dp[cur][capacity] != -1) return dp[cur][capacity];
        auto includeItem = 0, excludeItem =0;
        /* If we can include it then we try to include it */
        if(A[cur] <= capacity){
            includeItem = A[cur] + backpackRecursive(capacity-A[cur], A, dp, cur+1);
        }
        excludeItem = backpackRecursive(capacity, A, dp, cur+1);
        /* Memoize value and return */
        return dp[cur][capacity] = max(excludeItem, includeItem);
    }
    int backPack(int capacity, vector<int> &A) {
        if(A.empty()) return 0;
        int n = SIZE(A);
        /* DP array with i for our index and value and the vector 
        * holding the max value with each capacity*/
        vvi dp(n, vi(capacity+1, -1));
        return backpackRecursive(capacity, A, dp);
    }
};
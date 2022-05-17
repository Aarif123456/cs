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
    /* First attempt to get a better bottom-up approach with a better complexity */
    int backPack(int capacity, vector<int> &A) {
        if(A.empty()) return 0;
        int n = SIZE(A);
        /* DP array with i for our index and value and the vector 
        * holding the max value with each capacity*/
        vvi dp(n, vi(capacity+1, 0));
        /* Set up - if we have one weight then we only store that weight */
        FORL(c, 0, capacity){
            if(A[0] <= c){
                dp[0][c] = A[0];
            }
        }
        FOR(i, 1, n){
            FORL(c, 0, capacity){
                auto includeItem = 0, excludeItem = 0;
                if(A[i] <= c){
                    /* Note that c-A[i] is the remaining capacity after adding the item*/
                    includeItem = A[i] + dp[i-1][c-A[i]];
                }
                excludeItem = dp[i-1][c];
                dp[i][c] = max(includeItem, excludeItem);
            }
        }
        retrieveSelectedItem(dp, A, A);
        return dp[n-1][capacity];
    }
    /* In the version where the profit and weight differ we would need the weight array */
    unordered_set<int> retrieveSelectedItem(const vvi& dp, const vi& weight,  const vi& profit){
        if(dp.empty()) return unordered_set<int>();
        int lastItem = SIZE(dp)-1;
        int capacity = SIZE(dp[0])-1;
        unordered_set<int> selected;
        auto totalProfit = dp[lastItem][capacity];
        FORR(i, lastItem, 0){
            if((i==0 && totalProfit != 0 ) || 
               (i>0 && totalProfit != dp[i-1][capacity])){
                capacity -= weight[i];
                totalProfit -= profit[i];
                selected.insert(i);
            }
        }
        TRAV(element, selected){
            cout << weight[element] << ","; 
        }
        cout << endl;
        return selected;
    }
};
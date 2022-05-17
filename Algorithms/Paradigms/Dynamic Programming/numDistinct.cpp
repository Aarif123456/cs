typedef unsigned long long ull; 
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<ull> vl; 
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

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = SIZE(s), m = SIZE(t);
        vl dp(m+1, 0);
        dp[0] = 1;
        FORL(j, 1, n){
            FORR(i, m, 1) {
                dp[i] += s[j-1] == t[i-1] ? dp[i-1] : 0;
            }
        }
       return dp[m];
    }
};
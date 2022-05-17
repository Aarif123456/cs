typedef vector<string> vs; 
  
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
    vector<vs> dp;
    vector<string> generateParenthesis(int n) {
        if(n==0) return vs(1, "");
        if (n==1) return vs(1, "()");
        if(dp.size() <=n) dp.resize(n+1, vs());
        if(!dp[n].empty()) return dp[n];
        vs out;
        /* We want to only add parenthesis when we know it is valid*/
        REP(c, n){
            TRAV(left, generateParenthesis(c)){
                TRAV(right, generateParenthesis(n-1-c)){
                    out.push_back("("+left+")"+right);
                }
            }
        }
        dp[n] = out;
        return dp[n];
    }
};

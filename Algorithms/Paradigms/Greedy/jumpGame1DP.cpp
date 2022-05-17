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
    bool canJump(vector<int>& nums) {
        auto n = SIZE(nums);
        auto end = n-1;
        vi dp(n, 0);
        FORR(i, end, 0){
            auto jump = nums[i];
            dp[i] = i;
            FORL(j,1,  min(jump, end-i)){
                dp[i] = max(dp[i], dp[i+j]);
                if(dp[i] == end) break;
            }
        }
        TRAV(val, dp){
            cout << val << ",";
        }
        cout << endl;
        return dp[0] == end;
    }
};
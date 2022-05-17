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

/* Greedy solution */
class Solution {
public:
    int jump(vector<int>& nums) {
        auto n = SIZE(nums);
        int curDist =  min(nums[0], n-1), maxDist=0, jumps=0;
        FORL(i, 1, curDist){
            auto curJump = min(nums[i]+ i, n-1);
            maxDist = max(maxDist, curJump);
            if(i==curDist){
                jumps++;
                curDist = maxDist;
            }
        }
        return curDist >= n-1 ? jumps : -1;
    }
};
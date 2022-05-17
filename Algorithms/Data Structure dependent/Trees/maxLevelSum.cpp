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
#define REP(i, n) FOR(i, 0, n) 
/* general shortcut */
#define ALL(v) v.begin(), v.end() 
#define SIZE(v) static_cast<int>(v.size()) 
#define SORT(v) sort(ALL(v)) 
#define REVERSE(v) reverse(ALL(v)) 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    constexpr int maxLevelSum(TreeNode* root) {
        vi sums(10000);
        auto maxVal = maxLevelSumRecurse(root, 0, sums);
    }

    constexpr int maxLevelSumRecurse(TreeNode* cur, int curLevel, vi& sums, ll curMax=INT_MIN){
        if(cur == nullptr) return curMax;
        sums[curLevel] += cur->val;
        curMax = max(curMax, sums[curLevel]);
        if(curMax == sums[curLevel] ) maxLevel = curLevel;

    }
};
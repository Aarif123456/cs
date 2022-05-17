typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<bool> vb; 
typedef vector<vb> vvb; 
/* For loop excluding end*/
#define FOR(i, b, c) for (int(i) = (b); (i) < (c); (i)++) 
/* Traverse collection */
#define TRAV(a, b) for (auto&(a) : (b)) 
/* Quick for loop */
#define REP(i, n) FOR(i, 0, n)
/* general shortcut */
#define ALL(v) v.begin(), v.end() 
#define SIZE(v) static_cast<int>(v.size()) 

class Solution {
public:
    bool canPartitionRecurse(vi& nums, int targetSum, vb& memo, int cur){
        auto sz = SIZE(nums);
        if(cur == sz || memo[targetSum]) return memo[targetSum];
        auto num = nums[cur];
        unordered_set<int> used;
        REP(i, targetSum-num+1){
            if(used.find(i) != used.end()) continue;
            if(memo[i] && !memo[i+num]){
                used.insert(i+num);
                memo[i+num] = true;
            } 
        }
        return canPartitionRecurse(nums, targetSum, memo, cur+1);
    }
    bool canPartition(vector<int>& nums) {
        auto sz = SIZE(nums);
        if(sz==0) return true;

        auto sum = accumulate(nums.begin(), nums.end(), 0);
        /* Whole thing has to be even */
        if(sum%2 != 0) return false;
        auto targetSum = sum/2;
        vb memo(targetSum+1);  
        memo[0] = true;
        return canPartitionRecurse(nums, targetSum, memo, 0);
    }
};
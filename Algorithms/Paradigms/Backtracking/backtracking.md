Backtracking
1. choice
2. constraint 
3. goal

1. Pick a starting point.
2. while(not goal reached)
3.    For each path from the starting point.
4.        check if selected path satisfies constraint, if yes select it
5.        and make recursive call to rest of the problem
6.        undo the current move.
7.    End For
8. If none of the move works out, return false, NO SOLUTON.

Note: sorting can help handle tricky conditions such as duplicates

https://leetcode.com/problems/palindrome-partitioning/discuss/182307/Java:-Backtracking-Template-General-Approach

https://leetcode.com/problems/subsets/discuss/27281/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning)

```cpp
typedef vector<int> vi;
typedef vector<vi> vvi; 
typedef vector<int>::iterator vi_it;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vvi out;
        backtrack(out, nums.begin(), nums.end());

        return out;
    }
private:
    void backtrack(vvi& out, vi_it start, vi_it end){
        vi temp;
        std::sort(start, end);
        backtrack(out, temp, start, end);
    }

    void backtrack(vvi& out, vi& temp, vi_it start, vi_it& end){
        out.push_back(vi(temp.begin(), temp.end()));
        for(auto i = start; i != end; i++){
            temp.push_back(*i);
            backtrack(out, temp, i+1, end);
            temp.pop_back();
        }
    }
};
```
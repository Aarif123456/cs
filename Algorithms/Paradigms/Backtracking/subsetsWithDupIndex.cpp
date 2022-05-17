typedef vector<int> vi;
typedef vector<vi> vvi; 

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vvi out;
        std::sort(nums.begin(), nums.end());
        backtrack(out, nums);

        return out;
    }
private:
    void backtrack(vvi& out, vi& nums){
        vi temp;
        backtrack(out, temp, nums, 0);
    }

    void backtrack(vvi& out, vi& temp, vi& nums, int start){
        out.push_back(vi(temp.begin(), temp.end()));
        for(auto i=start; i<nums.size(); i++){
            /* skip duplicates */
            if(i > start && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            backtrack(out, temp, nums, i+1);
            temp.pop_back();
        }
    }


};
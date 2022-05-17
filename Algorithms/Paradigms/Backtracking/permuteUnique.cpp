#define MAX_LENGTH 10
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::bitset<MAX_LENGTH> bool_set;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vvi out;
        backtrack(nums, out);

        return out;
    }

private:
    void backtrack(vi& nums, vvi& out){
        vi temp;
        bool_set visited;
        std::sort(nums.begin(), nums.end());
        backtrack(nums, out, temp, visited);
    }

    void backtrack(vi& nums, vvi& out, vi& temp, bool_set& visited){
        if(nums.size() == temp.size()) out.push_back(vi(temp.begin(), temp.end()));

        for(int i = 0; i < nums.size(); i++){
            /** Only go forward with duplicate if we have 
             * used the previous - which ensures 
             */
            if(visited[i] || (i && !visited[i-1] && nums[i-1] == nums[i])) continue;
            temp.push_back(nums[i]);
            visited[i] = true;

            backtrack(nums, out, temp, visited);

            temp.pop_back();
            visited[i] = false;
        }
    }
};
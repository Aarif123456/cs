#define MAX_LENGTH 10
typedef vector<int> vi;
typedef vector<vi> vvi; 
typedef std::bitset<MAX_LENGTH> boolSet;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vvi out;
        backtrack(out, nums);
        return out;
    }
private:
    void backtrack(vvi& out, vi& nums){
        vi temp;
        boolSet visited;
        // std::sort(nums.begin(), nums.end());
        backtrack(out, temp, nums, visited);
    }

    void backtrack(vvi& out, vi& temp, vi& nums, boolSet& visited){
        if(temp.size() == nums.size()) out.push_back(vi(temp.begin(), temp.end()));
        for(int i = 0; i < nums.size(); i++){
            if(visited[i]) continue;

            temp.push_back(nums[i]);
            visited[i] = true;

            backtrack(out, temp, nums, visited);

            temp.pop_back();
            visited[i] = false;
        }
        
    }
};
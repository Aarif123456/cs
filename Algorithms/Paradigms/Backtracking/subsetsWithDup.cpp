typedef vector<int> vi;
typedef vector<vi> vvi; 
typedef vector<int>::iterator vi_it;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
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
        for(auto i=start; i!= end; i++){
            /* skip duplicates*/
            if(i>start && *(i-1) == *i) continue;
            temp.push_back(*i);
            backtrack(out, temp, i+1, end);
            temp.pop_back();
        }
    }


};
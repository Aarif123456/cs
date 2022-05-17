class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int best = 0;
        int l = 0;
        for(int r = 0; r < nums.size(); r++){
            if(nums[r] == 0) k--;
            while(l <= r && k < 0){
                if(nums[l++] == 0) k++;
            }
            best = std::max(best, r-l+1);
        }

        return best;
    }
};
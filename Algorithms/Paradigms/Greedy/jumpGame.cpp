class Solution {
public:
    bool canJump(vector<int>& nums) {
        int left = 0;
        if(!nums.empty()) nums.pop_back();
        for(auto n: nums){
            left = max(n, left-1);
            if (left <= 0) return false;
        }

        return true;
    }
};
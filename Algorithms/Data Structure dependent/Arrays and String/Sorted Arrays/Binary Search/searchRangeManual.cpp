class Solution {
public:
    int binarySearch(vector<int>& nums, int target){
        if(nums.empty()) return -1;
        auto l = nums.begin(), r = nums.end();
        while(l<r){
            auto m = l + (r-l)/2;
            if(*m < target) l = m+1;
            else r = m;
        }

        return r - nums.begin();
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> out;
        auto lo = binarySearch(nums, target);
        if(lo < 0 || lo >= nums.size() || nums[lo] != target) return {-1, -1};
        auto hi = binarySearch(nums, target+1) - 1;
        
        return {lo, hi};
    }
};
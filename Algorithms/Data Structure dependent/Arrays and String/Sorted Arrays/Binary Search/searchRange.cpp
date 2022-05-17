class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> out;
        if(!std::binary_search(nums.begin(), nums.end(), target)) return vector<int>(2, -1);
        auto lower = std::lower_bound(nums.begin(), nums.end(), target);
        out.push_back(lower - nums.begin());
        auto high = std::upper_bound(lower, nums.end(), target);
        out.push_back(high - nums.begin() - 1);

        return out;
    }
};
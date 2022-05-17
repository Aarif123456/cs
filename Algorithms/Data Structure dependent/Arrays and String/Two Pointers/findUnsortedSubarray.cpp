typedef vector<int> vi;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        auto n = nums.size();
        vi maxL2R(n), minR2L(n);
        auto min = [&](int a, int b){return std::min(a, b);};
        auto max = [&](int a, int b){return std::max(a, b);};
        std::partial_sum(nums.rbegin(), nums.rend(), minR2L.rbegin(), min);
        std::partial_sum(nums.begin(), nums.end(), maxL2R.begin(), max);
        int i = 0, j = n-1;
        /* going from the left side we cannot have any number smaller than it on the right hand side*/
        for(i = 0; i < n && nums[i] <= minR2L[i]; i++);
        /* From the right side - number don't need to be sorted
           iff we no number bigger than it to it's left
         */
        for(j = n-1; j > i && nums[j] >= maxL2R[j]; j--);

        return j-i+1;
    }   
};
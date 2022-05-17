class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n+1, 1), right(n+1, 1), out(n,1);
        std::partial_sum(nums.begin(), nums.end(), left.begin()+1,std::multiplies<>());
        std::partial_sum(nums.rbegin(), nums.rend(), right.rbegin()+1, std::multiplies<>());
        // std::transform(left.begin(), left.end()-1, right.begin()+1, out.begin(), std::multiplies<>());

        /* right: 24,12,4,1,1 
         * left: 1,1,2,6,24 
         */
        for(int i = 0; i < n; i++)
            out[i] = left[i] * right[i+1];

        return out;
    }
};
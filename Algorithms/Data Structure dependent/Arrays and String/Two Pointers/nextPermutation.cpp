class Solution {
public:
    /** 4 parts:
     * 1. check if descending: if so reverse array and we are done
     * 2. find "k" the first element not in descending order starting from the back
     * 3. Find "l" the first element bigger than k starting from the back and swap with "k"
     * 4. reverse the array from A[k+1, end] - because it was in descending order and the next permutation will be in ascending order
     * */
    auto getDescending(vector<int>& nums){
        /* Find element not in descending order */
        for(auto x = nums.rbegin(); x+1 != nums.rend(); x++){
            if(*x > *(x+1)) return x+1;
        }

        return nums.rend();
    }

    void nextPermutation(vector<int>& nums) {
        /* Swap must be within A[k..end] */
        auto k = getDescending(nums);

        if(k == nums.rend()) std::reverse(nums.begin(), nums.end());
        else{
            auto l = nums.rbegin();
            for(; l < k; l++){
                if(*l > *k) break;
            }
            std::iter_swap(l, k);
            std:reverse(nums.rbegin(), k);
        }
    }
};
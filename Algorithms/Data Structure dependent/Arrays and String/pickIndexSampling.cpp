class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& vals) {
        nums = vals;
    }
    
    int pick(int target) {
        /** We follow the following intuition - we can create a random probability 
         * by choosing one item from our bucket depending in the number of items in 
         * the bucket
         * So, item 1 had a 100% probability of being picked
         * Item 2 has 50% of replacing item 1
         * Item 3 had a 33% chance of replacing either 1 or 2
         * */
        int result = -1;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target && std::rand() % ++count == 0) 
                result = i;
        }

        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
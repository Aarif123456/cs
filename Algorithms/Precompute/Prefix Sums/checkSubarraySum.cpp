class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        int sum = 0;
        counter[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            auto n = nums[i];
            sum += n;
            if(k) sum %= k;
            if(counter.find(sum) != counter.end()){
                if(i-counter[sum] > 1) return true;
            } 
            else counter[sum] = i;
        }

        return false;
    }
};
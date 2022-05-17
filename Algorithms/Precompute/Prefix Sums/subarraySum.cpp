class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        map[0] = 1;
        int sum = 0;
        int count = 0; 
        for(auto n: nums){
            sum += n; 
            if(map.count(sum-k) > 0) count += map[sum-k];
            if(map.count(sum) == 0) map[sum] = 0;
            map[sum]++;
        }
        
        return count;
    }
};
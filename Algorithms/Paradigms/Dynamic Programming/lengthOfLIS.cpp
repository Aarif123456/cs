typedef vector<int> vi; 

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        vi dp(n, 1);
        for(int i = 0; i < n; ++i){
            for (int j = i; j >= 0; --j) {
                /* New sub array will consume the elements it is smaller */
                if(nums[j] < nums[i])
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        int ans = INT_MIN;
        for(auto n: dp)
            ans = max(ans, n);
        return ans;
    }
};
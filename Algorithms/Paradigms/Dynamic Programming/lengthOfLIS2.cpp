typedef vector<int> vi; 

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vi piles;
        piles.reserve(n);
        for(auto n: nums){
            auto low = std::lower_bound (piles.begin(), piles.end(), n);
            int i = low - piles.begin();
            if(i == piles.size()) piles.push_back(n);
            else piles[i] = n;
        }

        return piles.size();
    }
};
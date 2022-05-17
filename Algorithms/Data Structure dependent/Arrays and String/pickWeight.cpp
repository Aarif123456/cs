typedef vector<int> vi;
class Solution {
public:
    vi nums;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution;

    Solution(vector<int>& w){
        assert(w.size() > 0);
        std::partial_sum(w.begin(), w.end(), std::back_inserter(nums));
        distribution = std::uniform_int_distribution<int>(1, nums.back());
    }
    
    int pickIndex(){
        auto ans = std::lower_bound(nums.begin(), nums.end(), distribution(generator));
        return ans - nums.begin();
    }
};

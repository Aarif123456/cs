typedef vector<int> vi;
class Solution {
public:
    std::unordered_map<int, vi> mapper;
    std::default_random_engine generator;

    Solution(vector<int>& w) {
        for(int i = 0; i < w.size(); i++){
            mapper[w[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        std::uniform_int_distribution<int> distribution(0,mapper[target].size()-1);
        return mapper[target][distribution(generator)];
    }
};

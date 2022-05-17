typedef vector<int> vi;

class Solution {
public:
    vector<int> createMonotonic(vi& nums){
        vi out(nums.size(), -1);
        auto cur = out.rbegin();
        std::stack<vi::reverse_iterator> mono;
        for(auto i = nums.rbegin(); i != nums.rend(); i++){
            while(!mono.empty() && *mono.top() < *i) mono.pop();
            if(!mono.empty()) *cur = *mono.top();
            mono.push(i);
            cur++;
        }

        return out;
    }

    vector<int> findBuildings(vector<int>& heights) {
        auto nextGreater = createMonotonic(heights);
        vi out;

        for(int i = 0; i < heights.size(); i++){
            if(nextGreater[i] == -1) out.push_back(i);
        }

        return out;

    }
};
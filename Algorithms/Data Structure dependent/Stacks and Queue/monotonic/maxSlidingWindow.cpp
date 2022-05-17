class Solution {
public:
    void addNum(std::deque<int>& mono, int n){
        while(!mono.empty() && mono.front() < n) mono.pop_front();
        mono.push_front(n);
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty() || k == 0) return vector<int>();
        std::deque<int> mono;
        int n = nums.size();
        for (int i = 0; i < k; i++) addNum(mono, nums[i]);

        vector<int> out = {mono.back()};
        for (int i = k; i < n; i++){
            addNum(mono, nums[i]);
            if(mono.back() == nums[i-k]) mono.pop_back();
            out.push_back(mono.back());
        }

        return out;
    }
};
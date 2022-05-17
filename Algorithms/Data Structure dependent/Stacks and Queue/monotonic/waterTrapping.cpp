typedef vector<int> vi;
class Solution {
public:
    vector<int> nextGreaterElement(vi& height){
        std::stack<int> mono;
        vi next(height.size(), -1);
        auto cur = next.rbegin();
        for (auto i = height.rbegin(); i != height.rend(); ++i){
            while(!mono.empty() && mono.top() < *i){
                mono.pop();
            }
            *cur = mono.empty() ? -1 : mono.top();
            cur++;
            mono.push(*i);
        }

        return next;
    }

    int trap(vector<int>& height) {
        auto next = nextGreaterElement(height);
        int n = height.size(), sum = 0, last = 0, target = 0;
        for(int i = 1; i < n; i++) {
            last = height[i-1];
            target = next[i-1];
            if(target == -1) continue;
            while(i<n && height[i] != target) sum += std::max(last - height[i++], 0);
        }

        return sum;
    }
};
typedef vector<int> vi;
typedef pair<int, int> pii;

#define SIZE(v) (static_cast<int>(v.size()))

class Solution {
public:
    vi findMaxWidth(vi& nums){
        std::stack<int> mono;
        auto n = SIZE(nums);
        vi out(n);
        std::iota(out.rbegin(), out.rend(), 0);
        for (int i = 0; i < n; i++){
            while(!mono.empty() && nums[mono.top()] > nums[i]){
                auto idx = mono.top(); mono.pop();
                out[idx] = i - idx - 1;
            }
            mono.push(i);
        }

        return out;
    }

    int largestRectangleArea(vector<int>& heights) {
        /* Find how many sub arrays we can have which start with 
         * the current element and where the head is the minimum
         */
        auto heads = findMaxWidth(heights);
        vi rev(heights.rbegin(), heights.rend());
        /* Same as head but for tails */
        auto tails = findMaxWidth(rev);
        std::reverse(tails.begin(), tails.end());
        auto n = SIZE(heights);
        int best = 0;

        for (int i = 0; i < n; i++){
            int cur = (heads[i]+tails[i]+1)*heights[i];
            best = std::max(best, cur);
        }

        return best;

    }
};
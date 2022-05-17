typedef vector<int> vi;

class Solution {
public:
    int trap(vector<int>& height) {
        std::stack<int> stack;
        int n = height.size(), sum = 0, i = 0;
        while(i < n) {
            if(stack.empty() || height[stack.top()] > height[i]) stack.push(i++);
            else{
                int valley = height[stack.top()]; stack.pop();
                if(!stack.empty()) {
                    int leftWall = stack.top();
                    /* Since stack is in decreasing order we know the top value is gonna
                     * be smaller. We calculate the water using the smaller wall
                     */
                    int h = std::min(height[i], height[leftWall]) - valley;
                    int dist = (i - leftWall - 1);
                    sum += h * dist;
                }
            }
        }

        return sum;
    }
};
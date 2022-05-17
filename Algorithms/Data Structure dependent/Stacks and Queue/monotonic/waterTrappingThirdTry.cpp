class Solution {
public:
    int trap(vector<int>& heights) {
        std::stack<int> stack;
        int n = heights.size(), i = 0, sum = 0;

        while(i<n){
            if(stack.empty() || heights[i] < heights[stack.top()]){
                stack.push(i++);
            }
            else{
                auto valley = heights[stack.top()]; stack.pop();
                if(!stack.empty()){
                    auto leftWall = stack.top();
                    // cout << "leftWall:" << leftWall << "rightWall:" << heights[i] << endl;
                    auto h = min(heights[leftWall], heights[i]);
                    sum += (h - valley) * (i-leftWall-1);
                    // cout << "h:" << h << "add:" << (h - valley) * (i-leftWall-1)<< endl;
                    assert((h - valley) * (i-leftWall-1) >= 0);
                }
            }
        }

        return sum;
    }
};
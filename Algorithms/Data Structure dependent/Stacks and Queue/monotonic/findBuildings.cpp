typedef vector<int> vi;

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size(), biggestSeen = INT_MIN;
        vi out;

        for(int i = n-1; i >= 0 ; i--){
            if(biggestSeen < heights[i]) {
                out.push_back(i);
                biggestSeen = heights[i];
            }
        }

        std::reverse(out.begin(), out.end());
        return out;
    }
};
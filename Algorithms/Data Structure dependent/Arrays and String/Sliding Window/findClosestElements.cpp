class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto lo = arr.begin(), hi = arr.end()-1;

        while(hi-lo+1 > k){
            if(std::abs(*lo-x) <= std::abs(*hi-x)) hi--;
            else lo++;
        }

        return std::vector<int>(lo, hi+1);
    }
};
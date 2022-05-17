typedef vector<int> vi;
class Solution {
public:
    bool canShip(vi& weights, int capacity, int maxDays){
        int days = 0, curWeight = 0;

        for(auto &w : weights){
            curWeight += w;
            if(curWeight > capacity){
                curWeight = w;
                days++;
                if(days >= maxDays) return false;
            }
        }

        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *std::max_element(weights.begin(), weights.end());
        int r =  std::accumulate(weights.begin(), weights.end(), 0);
        while(l < r){
            int m = (l+r)/2;
            if(canShip(weights, m, days)) r = m;
            else l = m+1;
        }

        return r;
    }
};
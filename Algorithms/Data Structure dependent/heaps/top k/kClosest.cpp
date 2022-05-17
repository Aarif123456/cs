typedef vector<int> vi; 
typedef vector<vi> vvi; 
/* For loop excluding end*/
#define FOR(i, b, c) for (int(i) = (b); (i) < (c); (i)++) 
/* For loop backward */
#define FORR(i, b, c) for (int(i) = (b); (i) >= (c); --(i)) 
/* Traverse collection */
#define TRAV(a, b) for (auto&(a) : (b)) 
/* Quick for loop */
#define REP(i, n) FOR(i, 0, n)
/* general shortcut */
#define ALL(v) v.begin(), v.end() 
#define SIZE(v) static_cast<int>(v.size()) 
class Solution {
public:
    double static euclidDistance(double x1, double y1, double x2, double y2){
        double x = x1 - x2; 
        double y = y1 - y2;
        double dist;

        dist = sqrt(pow(x, 2) + pow(y, 2));                        
        return dist;
    }

    const bool static euclidCompare(const vi& v1, const vi& v2){
        auto dist1 = euclidDistance(v1[0], v1[1], 0, 0);
        auto dist2 = euclidDistance(v2[0], v2[1], 0, 0);
        return dist1 < dist2;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vi, vvi, decltype(&euclidCompare)> pq(euclidCompare);
        TRAV(point, points){
            pq.push(point);
            if(pq.size()>k) pq.pop();
        }
        vvi output(k);
        FORR(i, k-1, 0){
            output[i] = pq.top();
            pq.pop();
        }
        return output;
    }
};

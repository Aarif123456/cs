typedef vector<int> vi; 
typedef vector<vi> vvi; 
/* For loop excluding end*/
#define FOR(i, b, c) for (int(i) = (b); (i) < (c); (i)++) 
/* Traverse collection */
#define TRAV(a, b) for (auto&(a) : (b)) 
/* Quick for loop */
#define REP(i, n) FOR(i, 0, n)
/* general shortcut */
#define ALL(v) v.begin(), v.end() 
#define SIZE(v) static_cast<int>(v.size()) 
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vi, greater<>> pq;
        TRAV(n, nums){
            if(pq.size()<k || pq.top() <n){
                pq.push(n);
            }
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
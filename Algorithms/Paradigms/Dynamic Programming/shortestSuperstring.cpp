typedef unordered_set<char> uc; 
typedef vector<char> vc;
typedef vector<string> vs; 
/* For loop excluding end*/
#define FOR(i, b, c) for (int(i) = (b); (i) < (c); (i)++) 
/* Traverse collection */
#define TRAV(a, b) for (auto&(a) : (b)) 
/* Quick for loop */
#define REP(i, n) FOR(i, 0, n)
// define how edges are set-up in graph
const int FROM = 1;
const int TO = 0;

/*https://leetcode.com/problems/find-the-shortest-superstring/solution/*/
class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
    /*Our algorithm has 3 main components:
        1. Precompute overlap(A[i], A[j]) for all possible i, j.
        2. Calculate dp[mask][i], keeping track of the "parent" i for each j as described above.
        3 .Reconstruct the answer using parent information.
    */


    }
};
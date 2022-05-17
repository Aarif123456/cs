typedef vector<int> vi; 
typedef vector<vi> vvi; 
/* For loop excluding end*/
#define FOR(i, b, c) for (int(i) = (b); (i) < (c); (i)++) 
/* For loop going till end*/
#define FORL(i, b, c) for (int(i) = (b); (i) <= (c); (i)++) 
/* For loop backward */
#define FORR(i, b, c) for (int(i) = (b); (i) >= (c); --(i)) 
/* Traverse collection */
#define TRAV(a, b) for (auto&(a) : (b)) 
/* Quick for loop */
#define REP(i, rows) FOR(i, 0, rows)
/* general shortcut */
#define ALL(v) v.begin(), v.end() 
#define SIZE(v) static_cast<int>(v.size()) 
class Solution {
/* Idea we rack the left most one, the right most one and the height 
* at the current index
*/
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        auto n = SIZE(matrix[0]);
        auto m = SIZE(matrix);
        vi left(n, 0), right(n, n), height(n, 0);
        auto maxArea = 0;
        REP(i, m){
            auto curLeft = 0, curRight = n;
            /* Calculate height*/
            REP(j, n){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            /* Calculate right - we want right to be one more then
            * then the last consecutive  one in the matrix 
            */
            FORR(j, n-1, 0){
                if(matrix[i][j] == '1') {
                    right[j] = min(right[j], curRight);
                }
                else {
                    curRight = j;
                    right[j] = n; 
                }
            }
            /* Calculate the last element with a 1 for the current row
            * if we have a higher boundary in the above row - then 
            * we will use that left unless our left is more to the 
            * right
            */
            REP(j, n){
                if(matrix[i][j] == '1') {
                    left[j] = max(left[j], curLeft);
                }
                else{
                    curLeft = j+1;
                    left[j] = 0;
                }
            }

            REP(j, n){
                maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
            }
        }
        return maxArea;
    }
};
#define MAX_NUMBER 301
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
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        auto n = SIZE(matrix);
        auto m = SIZE(matrix[0]);
        vector<bitset<MAX_NUMBER>> bits(n);
        auto count = 0;
        REP(i, n){
            REP(j, m){
                if(matrix[i][j] == 1) bits[i][j] = true;
            }
        }
        TRAV(bit, bits){
            REP(i, m){
                cout << bit[i] <<",";
            }
            cout << endl;
        }
        cout << "______________________________" <<endl;
        /* Go through all all rows */
        REP(i, n-1){
            bitset<MAX_NUMBER> curBit;
            auto leftOverRows = n-i;
            auto lastSet = 0;
            REP(j, m){
                if(!bits[i][j]){
                    curBit.reset();
                    lastSet = j;
                } 
                curBit[j] = bits[i][j];
                /* Compare to next line if it matches it has an array of size n if it doesn't we we reset our last index and try again 
                */
                auto curMatrixSize = curBit.count(); 
                REP(k, curMatrixSize){
                    cout << "i:" << i << ", j:"<<j << ", k:" << k <<endl;
                    cout << "lastSet1:" << lastSet<< endl;
                    if(curMatrixSize>=leftOverRows) {
                        curMatrixSize = leftOverRows;
                        lastSet = min(j, lastSet+1);
                        curBit[lastSet] = false; 
                        k--;
                        continue;
                    }
                    cout << "lastSet2:" << lastSet<< endl;
                    if((curBit & bits[i+1+k]).count() != curBit.count() ){
                        lastSet = min(j, lastSet+1);
                        curBit[lastSet] = false;
                        curMatrixSize = curBit.count();
                    }
                    count += k+1;
                }
            }
        }
        count += bits[n-1].count();
        return count;
    }
};
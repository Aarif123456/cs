typedef vector<string> vs; 
  
/* For loop excluding end*/
#define FOR(i, b, c) for (int(i) = (b); (i) < (c); (i)++) 
/* For loop going till end*/
#define FORL(i, b, c) for (int(i) = (b); (i) <= (c); (i)++) 
/* For loop backward */
#define FORR(i, b, c) for (int(i) = (b); (i) >= (c); --(i)) 
/* Traverse collection */
#define TRAV(a, b) for (auto&(a) : (b)) 
/* Quick for loop */
#define REP(i, n) FOR(i, 0, n) 
/* general shortcut */
#define ALL(v) v.begin(), v.end() 
#define SIZE(v) static_cast<int>(v.size()) 
#define SORT(v) sort(ALL(v)) 
#define REVERSE(v) reverse(ALL(v)) 

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return vs();
        return letterCombinationsRecursive(digits);
    }
    vector<string>letterCombinationsRecursive( string digits, int cur=0){
        if(cur>=digits.length()) return vs(1, "");
        unordered_map<char, string> possibleChars( {{'2',"abc"},{'3',"def"}, {'4',"ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}} );
        auto prev = letterCombinationsRecursive( digits, cur+1);
        auto s = possibleChars[digits[cur]];
        vs out;
        TRAV(last, prev){
            TRAV(c, s){
                out.push_back(c+last);
            }
        }
        return out;
    }

};
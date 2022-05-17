typedef vector<string> vs;
typedef string::iterator s_it;
class Solution {
public:
    /** 
     * 1.make sure result is valid
     * 2.remove min parenthesis
     * 3.only create unique string 
     * */
     
    vector<string> removeInvalidParentheses(string s) {
        vs out;
        helper(s, 0, 0, out, '(', ')');

        return out;
    }

private:
    void helper(string& s, int iStart, int jStart, vs& out, char openPar, char closePar){
        int i, numOpenParen = 0, numClosedParen = 0;
        /* 1. Go through an check if every close bracket has match */
        for(i = iStart; i < s.length() && numClosedParen <= numOpenParen; i++){
            if(s[i] == openPar) numOpenParen++;
            else if(s[i] == closePar) numClosedParen++;
        }

        /* 2. If all not matched then try to remove every extra close bracket */ 
        if(numClosedParen > numOpenParen) {
            i--;
            for(auto j = jStart; j <= i; j++){
                /** remove at each close parenthesis, 
                 * but skipping duplicate
                 */
                if(s[j] == closePar && (j == jStart || s[j-1] != closePar)){
                    string sub = s.substr(0, j) + s.substr(j+1);
                    helper(sub, i, j, out, openPar, closePar);
                }
            }
        }
        /** 3. If No invalid closed parenthesis detected. 
         *  Now check opposite direction - to match every open bracket
         *  or reverse back to original direction and add
         */
        else{
            string rev(s.rbegin(), s.rend());
            if(openPar == '(') helper(rev, 0, 0, out, ')','(');
            else out.push_back(rev);
        }
    }
};
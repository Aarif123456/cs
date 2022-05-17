typedef std::string::iterator s_it;
class Solution {
public:
    /* Idea: We can match regularly except "*" which we can track and use to starts searching
     * correctness follows from the fact * can match the previous string before the "*" so
     * we don't need to go back 
     */
    bool isMatch(string s, string r) {
        s_it p1 = s.begin(), p2 = r.begin(), lastStar = r.end(),  match = s.begin();
        while(p1 != s.end()){
            // cout << *p1 << "," << *p2 << endl;

            /* If we match then move both pointer */
            if(p2 != r.end() && (*p1 == *p2 || *p2 == '?')){
                p2++;
                p1++;
            }    
            /* Star means track pos after match*/
            else if(p2 != r.end() && *p2 == '*') {
                lastStar = p2++;
                match = p1;
            }
             /* If we have no stars before then we failed */
            else if(lastStar == r.end()) {
                return false;
            }
            /* If not match go back to last matched and try and match current char to pattern */
            else{
                p2 = lastStar+1;
                match++;
                p1 = match;
            }
        }
        /* Get rid of all stars */
        while(p2 != r.end() && *p2 == '*') ++p2;
        return p2 == r.end();
    }
};
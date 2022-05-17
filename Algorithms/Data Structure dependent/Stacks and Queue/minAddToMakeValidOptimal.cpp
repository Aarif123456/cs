class Solution {
public:
    int minAddToMakeValid(string s) {
        int lc=0, rc=0;
        for(auto &c : s){
            /* If see left brackets - then we need right brackets */
            if(c == '(') rc++;
            /* If we have right brackets then remove them cause we used them up */
            else if(rc) rc--;
            /* otherwise we need left brackets */
            else lc++;
        }

        return lc + rc;
    }
};
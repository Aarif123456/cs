class Solution {
public:
    void handleBackspace(string::reverse_iterator &i, string::reverse_iterator &end){
        int bc = 0;
        while(i != end && (bc > 0 || *i == '#')){
            if(*i == '#') bc++;
            else bc--;
            i++;
        }
    }

    bool backspaceCompare(string s, string t) {
        auto i = s.rbegin(), j = t.rbegin(), iEnd = s.rend(), jEnd = t.rend();
        

        while(i != iEnd && j != jEnd){
            /* BackCount = bc*/
            int bc1 = 0, bc2 = 0;
            handleBackspace(i, iEnd);
            handleBackspace(j, jEnd);
            /* If either reach end of string then we are done */
            if(i == iEnd || j == jEnd) break;
            if(*i != *j) return false;
            i++; j++;
        }

        handleBackspace(i, iEnd);
        handleBackspace(j, jEnd);
        return i == iEnd && j == jEnd;
    }
};
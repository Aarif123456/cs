class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        auto p1 = word.begin(), p2 = abbr.begin();
        auto e1 = word.end(), e2 = abbr.end();
        while(p1 != e1 && p2 != e2){
            int skip = 0;
            while(p2 != e2 && isdigit(*p2)){
                skip *= 10;
                skip += *p2 - '0';
                if(!skip) return false;
                p2++;
            }
            for(; skip > 0 && p1 != e1; skip--) p1++;
            if(skip) return false;
            if(p1 == e1 || p2 == e2) break;
            if(*p1 != *p2) return false;
            p1++; p2++;
                
        }

        return p1 == e1 && p2 == e2;
    }
};
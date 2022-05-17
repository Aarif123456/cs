class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int closeCount = 0;
        for(auto &c : s){
            if(c == ')') closeCount++;
        }
        /* track which one are open*/
        int openCount = 0;
        string out;

        for(auto &c : s){
            if(c == ')') {
                closeCount--;
                if(!openCount) continue;
                openCount--;
            }
            else if(c == '('){
                if(openCount == closeCount) continue;
                openCount++;
            }
            out.push_back(c);
        }

        return out;
    }
};


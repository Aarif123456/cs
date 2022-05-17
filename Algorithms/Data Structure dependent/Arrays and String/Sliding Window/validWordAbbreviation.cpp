class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int skip = 0;
        auto cur = abbr.begin(), end = abbr.end();
        string num="";
        for(auto &c : word){
            if(skip){
                skip--;
                continue;
            }
            while(isdigit(*cur)) {
                if(num == "" && *cur == '0') return false;
                num.push_back(*cur);
                cur++;
            }
            if(!num.empty()){
                skip = stoi(num)-1;
                num="";
                continue;
            }

            if(cur == end || c != *cur) return false;
            cur++;
        }

        return cur == end && skip == 0;
    }
};
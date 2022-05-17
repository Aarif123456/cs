class Solution {
public:
    /* Remove all extra "*" */
    string simplifyRegex(string &r){
        string out = "";
        for(auto&(c) : (r)){
            if(!out.empty() && out.back() == '*' && c == '*') continue;
            out += c;
        }

        return out;
    }

    bool helper(string &s, string &r, int p1 = 0, int p2 = 0){
        if(p1 == s.length() && p2 == r.length()) return true;
        if(p1 == s.length() || p2 == r.length()) return false;
        if(r[p2] == '?' || s[p1] == r[p2]) return helper(s, r, p1+1, p2+1);
        if(r[p2] == '*') return helper(s, r, p1+1, p2) || helper(s, r, p1, p2+1) || helper(s, r, p1+1, p2+1);
        return false;
    }

    bool isMatch(string s, string r) {
        r = simplifyRegex(r);
        return helper(s, r);
    }
};
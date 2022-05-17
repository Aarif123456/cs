class Solution {
public:
    int minAddToMakeValid(string s) {
        std::stack<int> stk;
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if(c=='(') stk.push(i);
            else if(c==')'){
                if(stk.empty()) ans++;
                else stk.pop();
            }
        }

        return ans + stk.size();
    }
};
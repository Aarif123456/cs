class Solution {
public:
    string removeDuplicates(string s, int k) {
        std::stack<std::pair<char, int>> stack;
        std::reverse(s.begin(), s.end());
        for(auto &c : s){
            if(!stack.empty() && stack.top().first == c){
                if(++(stack.top().second) == k) stack.pop();
            }
            else{
                stack.push(make_pair(c, 1));
            }
        }

        string out="";
        while(!stack.empty()){
            auto c = stack.top().first;
            if(--(stack.top().second) == 0) stack.pop();
            out.push_back(c);
        }

        return out;
    }
};
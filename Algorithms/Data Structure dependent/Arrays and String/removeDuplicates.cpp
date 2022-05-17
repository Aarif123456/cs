class Solution {
public:
    string removeDuplicates(string s) {
        string out = "";
        auto i = s.begin(), end = s.end();

        while(i != end){
            bool matched = false;
            while(!out.empty() && out.back() == *i) {
                matched = true;
                out.pop_back();
            }
            if(matched) i++;
            else out.push_back(*(i++));
        }

        return out;
    }
};
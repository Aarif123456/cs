class Solution {
public:
    /* Might not be worth adding and then subtracting strings */
    vector<string> restoreIpAddresses(string s) {
        const static std::regex re(R"(((1\d\d)|(2([0-4]\d|(5[0-5]))|[1-9]?\d))\.){3}((1\d\d)|(2([0-4]\d|(5[0-5]))|[1-9]?\d))");
        vector<string> out;
        for (int i = 1; i < 4; i++){
        }
        return std::regex_match(s, re);
    }
};
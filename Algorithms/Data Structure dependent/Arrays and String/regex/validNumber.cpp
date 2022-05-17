class Solution {
public:
    bool isNumber(string s) {
        /* (\+|-)? - Start with optional sign
         * Now we have 2 possible cases
         * 1. (\.\d+)  - Decimal with dot at front
         * 2. ((\d+)(\.)?\d*)  - Any other decimal or integer
         * End with
         * ((E|e)(+|-)?(\d)+)? - Allow Exponent
         */
        const static std::regex re(R"((\+|-)?((\.\d+)|((\d+)(\.)?\d*))((E|e)(\+|-)?(\d)+)?)");
        return std::regex_match(s, re);
    }
};
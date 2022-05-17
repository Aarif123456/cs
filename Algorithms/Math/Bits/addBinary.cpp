class Solution {
public:
    string addBinary(string a, string b) {
        string out;
        auto p1 = a.rbegin(), p2 = b.rbegin();

        bool carry = false, isSet = false;
        while(p1 != a.rend() || p2 != b.rend()){
            bool x = p1 != a.rend() && *(p1++) == '1';
            bool y = p2 != b.rend() && *(p2++) == '1';

            if(carry){
                isSet = !(x ^ y);
                carry = x | y;
            }
            else{
                isSet = x ^ y;
                carry = x & y;
            }

            if(isSet) out.push_back('1');
            else out.push_back('0');
        }

        if(carry) out.push_back('1');

        std::reverse(out.begin(), out.end());
        return out;
    }
};
class Solution {
public:
    string addStrings(string num1, string num2) {
        auto a = num1.rbegin(), b = num2.rbegin();
        int carry = 0;
        string out;
        while(a != num1.rend() || b != num2.rend()){
            int x = a != num1.rend() ? *(a++) - '0' : 0;
            int y = b != num2.rend() ? *(b++) - '0' : 0;
            int ans = x+y+carry;
            carry = ans/10;
            ans %= 10;
            out.push_back(ans + '0');
        }

        if(carry) out.push_back(carry + '0');
        std::reverse(out.begin(), out.end());

        return out;
    }
};
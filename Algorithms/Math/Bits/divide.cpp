class Solution {
public:
    int divide(int A, int B) {
        if(A == INT_MIN && B == -1) return INT_MAX;
        bool pos =  (A > 0) == (B > 0);
        unsigned a = abs(A), b = abs(B), ans = 0;
        for(int k = 31; k >= 0; k--){
            /* If we can divide by 2^k and still have a */
            if(a >> k >= b){
                /* It is safe to subtract B from A, 2^k time*/
                ans += 1 << k;
                /* Subtract number of B's we have subtracted to get modulus */
                a -= b << k;
            }
        }

        int res = (signed) ans;
        if(res < 0 ) return pos ? INT_MAX : INT_MIN;

        return pos ? res : -res;
    }
}; 


class Solution {
public:
    constexpr double myPow(double x, int n) {
        assert(x || n); /* No 0/0*/
        if(x==0) return 0; /* 0^n = 0 */
        if(n==1) return x; /* x^1 == 1*/
        if(x==1 || n==0) return 1;
        /* Case 1: negative get reciprocal - -(n+1) 
         * to avoid overflow */
        if(n<0) return (1.0/x) * myPow(1.0/x, -(n+1));
        /*Case 2: If even square number and divide exponent by 2*/
        if(n%2==0) return myPow(x*x, n/2);
        /* Case 3: handle odd by multiplying current value */
        return x*myPow(x*x, n/2);
    }
};
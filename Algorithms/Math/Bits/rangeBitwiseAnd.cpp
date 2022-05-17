class Solution {
public:
    int extractLSB(int x){
        return x & ~(x-1);
    }

    int resetLSB(int x){
        return x & (x-1);
    }

    int rangeBitwiseAnd(int left, int right) {
        int ans = 0, cur = left;
        while(cur){
            int lsb = extractLSB(cur);
            /** left%lsb gets us to where we are in the cycle to reset
             * lsb - (left%lsb) gets us the next number that would
             * reset our bit
             * 
             * INT_MAX-(lsb - left%lsb) - checks if the left+ the next number to reset the bit - would overflow
             **/
            if(INT_MAX-(lsb - left%lsb)<left || left + (lsb - left%lsb) > right ) ans |= lsb;
            cur = resetLSB(cur);
        }

        return ans;
    }
};
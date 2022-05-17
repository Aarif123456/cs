class Solution {
public:
    bool getBit(int i, int value){
        return value & (1L << i);
    }

    int setBit(int i, int value){
        return value |= (1L << i);
    }

    int getSum(int a, int b) {
        bool carry = false;
        int res = 0;

        for(int i = 0; i < 32; i++){
            bool x = getBit(i, a), y = getBit(i, b);
            bool isBitSet = false;
            if(carry){
                isBitSet = !(x ^ y);
                carry = x | y;
            }
            else {
                isBitSet = x ^ y;
                carry = x & y;
            }

            if(isBitSet) res = setBit(i, res);
        }

        return (int)res;
    }
};
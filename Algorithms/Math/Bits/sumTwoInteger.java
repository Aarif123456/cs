class Solution {
    public boolean checkBit(int x, long value){
        return (value & (1L << x)) != 0;
    }

    public long setBit(int x, long value){
        return value |= (1L << x);
    }
    public int getSum(int a, int b) {
        boolean carry = false;
        long ans = 0;
        /* Bits in Java are 32 bits: we go right to left*/
        for (int i=0; i<32; i++) {
            boolean x=checkBit(i, a), y=checkBit(i, b);
            boolean isBitSet = false;

            if(!carry){
                /* Logic of adding with carry */
                isBitSet = x ^ y;
                carry = x && y;
            }
            else{
                /* If we don't have a carry*/
                isBitSet = !(x ^ y);
                carry = x || y;
            }
            if(isBitSet) ans = setBit(i, ans);
        }

        int out = (int)ans;
        return out;
    }
}
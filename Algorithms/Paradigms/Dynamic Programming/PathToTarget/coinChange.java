class Solution {
    public int coinChange(int[] coins, int amount) {
        if(amount == 0) return 0;
        if(coins.length == 0) return -1;
        int[] arr = new int[amount+1];
        Arrays.fill(arr, amount+1);
        arr[0] = 0;
        for(int coin: coins){
            for(int i=coin; i<=amount; i++){
                arr[i] = Math.min(arr[i], arr[i-coin]+1);
            }
        }

        return  arr[amount] > amount ? -1 : arr[amount];
    }
}
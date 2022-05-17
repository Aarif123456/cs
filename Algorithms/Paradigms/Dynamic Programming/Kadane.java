class Solution {
    public int maxSubArray(int[] nums) {
        int maxSum = nums[0];
        int curSum;
        for (int i=0; i<nums.length; i++) {
            curSum = nums[i]; 
            maxSum = Math.max(curSum, maxSum);
            for (int j=i+1; j<nums.length; j++) {
                curSum+= nums[j];
                maxSum = Math.max(curSum, maxSum);
            }
        }

        return maxSum;
    }
}

class Solution {
    public int maxSubArray(int[] nums) {
        int maxSum = nums[0];
        int curSum = 0 ;
        for (int i=0; i<nums.length; i++) {
            curSum += nums[i]; 
            maxSum = Math.max(curSum, maxSum);
            if(curSum < 0){
                curSum = 0;
            }
        }

        return maxSum;
    }
}
class Solution {
    public int findMin(int[] nums) {
        /* If the point is lower then following will lead to the valley */
        int l=0, r=nums.length-1;
        if (nums[l] < nums[r]) return nums[l];
        while(l+1<r){
            int m = (l+r) /2;
            if(nums[l] > nums[m] ){
                r=m;
            }
            else{
               l=m;
            }
        }
         return nums[r];
    }
}


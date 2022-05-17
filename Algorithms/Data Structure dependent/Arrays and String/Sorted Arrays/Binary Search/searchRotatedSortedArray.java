class Solution {
    public int findPivot(int[] nums){
        if(nums[0] <= nums[nums.length-1]) return 0;
        int l=0, r=nums.length-1;

        while(l+1<r){
            int m = (l+r)/2;
            if(nums[m]>nums[r]){
                l=m;
            }
            else {
                r=m;
            }
        }

        return r;
    }

    public int binarySearch(int[] nums, int target, int l, int r){
        // System.out.println("l:"+l+"r:"+r);
        while(l<=r){
            int m = (l+r)/2;
            // System.out.println("m:"+m);
            if(nums[m] == target) return m;
            if(nums[m] < target ){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }

        return -1;
    }

    public int search(int[] nums, int target) {
        int pivot = findPivot(nums);
        int index = binarySearch(nums, target, pivot, nums.length-1);
        if(index == -1){
            index = binarySearch(nums, target, 0, pivot);
        }
        return index;
    }
}
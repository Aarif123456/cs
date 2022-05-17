class Solution {
    public List<List<Integer>> threeSum(int[] nums){
        List<List<Integer>> res = new LinkedList<>();
        Arrays.sort(nums);
        for(int i=0; i<nums.length-2; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            twoSums(nums, i, res);
        }
        return res;
    }

    public void twoSums(int[] nums, int index, List<List<Integer>> res){
        int l=index+1, r=nums.length-1;
        int target = -nums[index];
        while(l<r){
            int curSum = nums[l] + nums[r];
            if(curSum == target){
                res.add(Arrays.asList(-target, nums[l],nums[r]));
                /* Skip duplicates */
                while(l<r && nums[l] == nums[l+1]) l++;
                while(l<r && nums[r] == nums[r-1]) r--;
            }
            if(curSum <= target){
                l++;
            }
            if(curSum>=target){
                r--;
            } 
        }
    }
}
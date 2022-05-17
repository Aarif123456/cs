class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i=0; i<nums.length; i++) {
            int n = nums[i]; 
            if(map.containsKey(n)) return new int[]{i, map.get(n)} ;         
            map.put(target-n, i);
        }
        return new int[]{};

    }
}
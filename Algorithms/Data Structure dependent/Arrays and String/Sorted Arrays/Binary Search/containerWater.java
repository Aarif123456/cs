class Solution {
    public int maxArea(int[] height) {
        int l=0, r=height.length-1;
        int maxArea = 0;
        while(l<r){
            int curHeight = Math.min(height[l], height[r]);
            int curArea = curHeight * (r-l);
            maxArea = Math.max(curArea, maxArea);
            if(height[l] < height[r])l++;
            else r--;
       }
       return maxArea;
    }
}
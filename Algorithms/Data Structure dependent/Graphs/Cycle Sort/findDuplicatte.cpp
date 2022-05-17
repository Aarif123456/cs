class Solution {
public:
    /* Main idea: Do a binary search on the set of numbers [1,...,n]. 
     * For each number, count how many elements of the array are <= or >= that number. 
     * Recurse as appropriate.
     */
    int findDuplicate(vector<int>& nums) {
        int lo = 0, hi = int(nums.size()) - 1;

        while(lo<hi){
            /* Set the middle value as our guess */
            int mid = (lo+hi)/2;
            int count = 0;
            for(int i:nums) if(i<=mid) count++;
            /* 
            * If there are more number <= our guess the our repeated number must be <= then our guess.
            * So, we try search in the range [lo, mid]. Otherwise, the number must lie in (mid, hi]
            */
            if(count > mid) hi = mid;
            else lo = mid+1;
        }

        return lo;
    }
};
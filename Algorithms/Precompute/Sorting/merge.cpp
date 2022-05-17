class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /* Start from end of each vector and add to the empty portion of the 
         * future answer vector
         */
        auto n1 = nums1.rbegin()+n, n2 = nums2.rbegin(), ans = nums1.rbegin();

        /* Move bigger elements to end of array
         * Invariant: 
         * nums1[0...n1] - unmerged portion of nums1 - <= m elements
         * nums2[0...n2] - unmerged portion of nums2 - <= n elements
         * nums1[ans...end] - sorted merged array - each element in the answer array is 
         * bigger than or equal to any remaining element in either nums1 and nums2
         *
         * ans >= n1 - we will never overwrite any unprocessed elements in nums1 because 
         * ans can move at most m steps closer to n1. And, they are initially separated by m.
         */
        while(n1 != nums1.rend() && n2 != nums2.rend()){
            int n;
            if(*n1 >= *n2) *ans = *(n1++);
            else *ans = *(n2++);
            ans++;
        }

        /* Two cases at end of loop
         * 1.Processed all of nums1: Now we need to move the remaining nums2 element to
         * our answer list
         *
         * 2. Processed all of nums2: If we are done going through nums2 then ans == n1.
         * And, because every element in ans[nums] >= element in n1 and both array 
         * are sorted. We are done.
         */
        while(n2 != nums2.rend()) *(ans++) = *(n2++);

    }
};
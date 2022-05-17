typedef std::vector<int>::iterator vi_it;
typedef vector<int> vi;

class Solution {
public:
    /* Let [start, pivotIt, end] - be different points where the vector is partitioned
     * Invariant: 
     * A[start...pivotIt] < pivotIt
     * A[pivotIt] == pivotIt 
     * A[pivotIt...end] > pivotIt
     */
    auto partition(vi_it start, vi_it end, vi_it pivotIt){
        int pivotVal = *pivotIt;
        std::iter_swap(pivotIt, end); /* move pivot to end */
        auto pivotSpot = start;
        /* Move elements
         * Invariant: 
         * A[start...pivotSpot] < pivotVal
         * A[pivotSpot...i]  >= pivotVal 
         * A[i...end] - unclassified
         * At the end i == end - so unclassified is empty
         */
        for(auto i = start; i < end; i++)
            if(*i < pivotVal) std::iter_swap(i, pivotSpot++);

        /* Move pivot to the correct spot */
        std::iter_swap(end, pivotSpot);

        return pivotSpot;
    }

    auto quickselect(vi_it start, vi_it end, int k){
        /* ensure valid k value */
        assert(k >= 1 && k <= end-start);
        auto pivotIt = end, l = start, r = end;
        while(k != end - pivotIt){
            pivotIt = l + std::rand() % std::distance(l, r);
            pivotIt = partition(l, r-1, pivotIt);
            if(k > end - pivotIt) r = pivotIt;
            else if(k < end - pivotIt) l = pivotIt+1;
        }

        return pivotIt;
    }

    int findKthLargest(vector<int>& nums, int k) {
        auto x = quickselect(nums.begin(), nums.end(), k);

        return *x;
    }
};
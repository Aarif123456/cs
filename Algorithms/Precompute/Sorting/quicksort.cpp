typedef std::vector<int>::iterator vi_it;
class Solution {
public:
    /* Let [start, lt, eq, end] - be different points where the vector is partitioned
     * Invariant: 
     * A[start...lt-1] < pivot
     * A[lt...eq-1] == pivot - sorted 
     * A[eq...end] > pivot
     */
    void quicksort(vi_it start, vi_it end){
        if(end-start < 1) return;
        int pivot = *end;
        auto lt = start;

        /* Move smaller elements 
         * Invariant: 
         * A[start...lt-1] < pivot
         * A[lt...gte] - unclassified
         * A[gte...end] >= pivot
         * At the end gte==lt - so unclassified is empty
         */
        for(auto gte = end; gte > lt; gte--){
            while(*lt < pivot) lt++; 
            if(*gte >= pivot || gte <= lt) continue; 
            std::iter_swap(gte, lt);
        }
        
        /* Guaranteed to stop because end pivot is at end */
        while(*lt < pivot) lt++; 
        assert(*lt >= pivot);

        /* Move pivot element to position 
         * Invariant: 
         * A[lt...eq-1] == pivot
         * A[eq...gt] - unclassified
         * A[gt...end] > pivot
         * At the end gt==eq - so unclassified is empty
         */
        auto eq = lt;
        for(auto gt = end; gt > eq; gt--){
            while(*eq == pivot && eq < gt) eq++; 
            if(*gt > pivot || gt == eq) continue; 
            std::iter_swap(gt, eq);
        }
        while(*eq == pivot && eq < end) eq++;
        assert(*eq > pivot || eq == end);

        quicksort(start, lt-1);
        quicksort(eq, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        // randomize so no inputs are super slow
        std::random_shuffle(nums.begin(), nums.end()); 
        quicksort(nums.begin(), nums.end()-1);
        return nums;
    }
};
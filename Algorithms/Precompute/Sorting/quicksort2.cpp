typedef std::vector<int>::iterator vi_it;
class Solution {
public:
    void quicksort(vi_it start, vi_it end){
        if(end-start < 1) return;
        int pivot = *end;
        auto lt = start;
        /* Move smaller elements before pivot */
        for(auto i = end; i > lt; i--){
            while(*lt < pivot) lt++;
            if(*i < pivot && i > lt) std::iter_swap(i, lt);
        }
        
        /* Guaranteed to stop because pivot is at end */
        while(*lt < pivot) lt++;
        assert(*lt >= pivot);

        auto eq = lt;
        for(auto i = end; i > eq; i--){
            while(*eq == pivot && eq < i) eq++;
            if(*i == pivot && i > eq) std::iter_swap(i, eq);
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
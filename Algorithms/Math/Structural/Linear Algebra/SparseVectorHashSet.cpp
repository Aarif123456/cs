class SparseVector {
public:
    unordered_map<int, int> vals;
    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i++){
            vals[i] = nums[i];
        }
    }
    

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        if(vec.vals.size() > vals.size()) return dotProduct(vals, vec.vals);
        return dotProduct(vec.vals, vals);
        
    }
private:
    int dotProduct(unordered_map<int, int>& val1, unordered_map<int, int>& val2){
        int sum = 0;
        for(auto item: val1){
            auto i = item.first, x = item.second;
            if(val2.count(i)) sum += val2[i] * x;
        }
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
struct Node{
    int index;
    int val;
};

class SparseVector {
public:
    list<Node> vals;

    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0) vals.push_back({i, nums[i]});
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        auto val1 = vals, val2 = vec.vals;
        int sum = 0;
        auto s1 = val1.begin(), s2 = val2.begin();
        auto e1 = val1.end(), e2 = val2.end();

        while(s1 != e1 && s2 != e2){
            if(s1->index < s2->index) s1++;
            else if(s2->index < s1->index) s2++;
            else{
                sum += s1->val * s2->val;
                s1++; s2++;
            }
        }

        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
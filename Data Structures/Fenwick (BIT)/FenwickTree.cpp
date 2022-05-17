

class NumArray {
private:
    int getLSB(int n){
        // we use two's complement to get the lsb
        return n & -n;
    }
public:
    vector<int> fenwickTree;
    vector<int> numVal;
    // construction takes O(N)
    NumArray(vector<int>& nums) {
        numVal = nums;
        /* The fenwick tree uses an empty parent node so it's one bigger */
        fenwickTree.resize(nums.size()+1, 0);
        for(int i=1; i<=nums.size(); i++ ){
            /* we are going to copy the array as is but also cascade the value to the parent*/
            fenwickTree[i] += nums[i-1]; 
            int parent = i +  getLSB(i);
            // if parent in range then add current index value to the 
            if(parent < fenwickTree.size()) fenwickTree[parent] += fenwickTree[i];
        }
        // cout << "intial tree " <<endl;
        // for (auto n: fenwickTree){
        //     cout << n << ",";
        // }
        // cout << endl;
    }
    
    // update will take log(n) time
    void update(int index, int val) {
        int oldVal = numVal[index];
        int updateVal = val-oldVal;
        numVal[index] = val;
        
        int parent = index+1;
        while(parent < fenwickTree.size()){
            fenwickTree[parent] += updateVal;
            parent +=  getLSB(parent);
        }
    }
    int getSum(int index){
        // convert to fenwick style
        index++;
        int sum = 0;
        // cout << "new val " << endl;
        while(index>0){
            // cout << "index=" << index << endl;
            sum+= fenwickTree[index];
            index -=  getLSB(index);
        }
        // cout << "sum for new val: " << sum << endl;
        return sum;
    }
    int sumRange(int left, int right) {
        // subtract left to make sum inclusive else it is exclusive
        return  getSum(right) - getSum(--left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
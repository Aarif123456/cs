  
typedef long long ll; 
typedef long double ld;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef vector<ld> vd; 
typedef vector<vd> vvd; 
typedef vector<ll> vl; 
typedef vector<vl> vvl; 
#define ALL(v) v.begin(), v.end() 

class FenwickTree
{
private:
    int getLSB(int n){
        // we use two's complement to get the lsb
        return n & -n;
    }
    vector<int> fenwickTree;

public:

    FenwickTree(int len)
    {
        fenwickTree.resize(len+1, 0);
    }

    // update will take log(n) time
    void update( int index, int updateVal) {
        int parent = index;
        while(parent < fenwickTree.size()){
            fenwickTree[parent] += updateVal;
            parent +=  getLSB(parent);
        }
    }
    
    int query( int index){
        int sum = 0;
        while(index>0){
            sum+= fenwickTree[index];
            index -=  getLSB(index);
        }
        return sum;
    }
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        vl longs, doubleLongs;
        for(auto n: nums) longs.push_back(n);
        for(auto n: longs) doubleLongs.push_back(n*2);

        /* We combine the values in here */
        set<ll> set;
        set.insert(ALL(longs));
        set.insert(ALL(doubleLongs));
        
        /*map original to range [1, sorted.size()]*/
        int rank = 0;
        unordered_map<ll, int> ranks;
        for (auto num : set) {
           ranks[num] = ++rank;
        }
        FenwickTree tree(ranks.size());
        int res = 0;

        // from right to left, because we want to find how many nums are smaller than 1/2 of current num on the right
        for (int i = static_cast<int>(doubleLongs.size())-1; i >= 0; i--) {
            res += tree.query(ranks[doubleLongs[i] / 2] - 1);
            tree.update(ranks[doubleLongs[i]], 1);
        }
        
        return res;
    }
};
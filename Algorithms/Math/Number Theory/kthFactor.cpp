class Solution {
public:
    int kthFactor(int n, int k) {
        if(!k) return -1;
        int sqrt = std::sqrt(n);

        for(int i=1; i<= sqrt; i++){
            if(n%i == 0) k--;
            if(!k) return i;
        }
        for(int i=sqrt; i>=1; i--){
            if(n%i == 0 && n/i != i) k--;
            if(!k) return n/i;
        }

        return -1;
    }
};
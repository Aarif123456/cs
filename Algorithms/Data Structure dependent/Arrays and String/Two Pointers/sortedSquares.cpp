typedef vector<int> vi;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vi out(nums.size());
        auto cur = out.begin();
        auto p1 = nums.begin();
        auto p2 = nums.rbegin();
        /** p1 goes for [0,∞]
         *  p2 goes from [-∞,0)
         */
        while(p1 != nums.end() && *p1 < 0) p1++;
        while(p2 != nums.rend() && *p2 >= 0) p2++;

        while(p1 != nums.end() && p2 != nums.rend()){
            int n;
            if(*p1 < -(*p2)) n = *(p1++); 
            else n = *(p2++); 
            *cur = n * n;
            cur++;
        }

        while(p1 != nums.end()) {
            *cur = *p1 * *p1;  
            cur++; p1++;
        }     
        while(p2 != nums.rend()) {
            *cur = *p2 * *p2;
            cur++; p2++;

        }

        return out;      
    }
};
#define MAX_DIGITS 10
typedef vector<int> vi;
class Solution {
public:
    vector<int> getNextGreater(vector<int>& nums){
        std::stack<int> mono;
        vi next(nums.size(), -1);
        auto cur = next.rbegin();
        for(auto p = nums.rbegin(); p != nums.rend(); p++){
            while(!mono.empty() && mono.top() <= *p){
                mono.pop();
            }

            *cur = mono.empty() ? -1 : mono.top();
            cur++;
            mono.push(*p);
        }

        return next;
    }
    /* Idea: We can just use a two pointer approach to create our output as and use 
     * our next greater to break ties. We can implement next bigger using monotonic
     */
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        std::array<int, MAX_DIGITS> count;
        count.fill(0);

        for(auto n: nums1) count[n]++;
        for(auto n: nums2) count[n]++;

        vi next1 = getNextGreater(nums1), next2 = getNextGreater(nums2), out;

        for (int i = MAX_DIGITS - 1; i >= 0; i--){
            if(k < count[i]) count[i] = k;
            k -= count[i];
        }

        auto p1 = nums1.begin(), p2 = nums2.begin();

        while(p1 != nums1.end() || p2 != nums2.end()){
            if(p1 != nums1.end() && count[*p1] <= 0){
                p1++;
                continue;
            }
            if(p2 != nums2.end() && count[*p2] <= 0){
                p2++;
                continue;
            }

            if( p2 == nums2.end() || (p1 != nums1.end() && *p1 > *p2) ){
                out.push_back(*p1);
                count[*p1]--;
                p1++;
            }
            else if(p1 == nums1.end() || (p2 != nums2.end() && *p2 > *p1)){
                out.push_back(*p2);
                count[*p2]--;
                p2++;
            }
            else{
                if(next1[nums1.end() - p1 - 1] > next2[nums2.end() - p2 - 1]){
                    out.push_back(*p1);
                    count[*p1]--;
                    p1++;
                }
                else{
                    out.push_back(*p2);
                    count[*p2]--;
                    p2++;
                }
            }
        }

        return out;
    }
};
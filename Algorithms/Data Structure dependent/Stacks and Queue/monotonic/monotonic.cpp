class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // hashmap for index mapping
        unordered_map<int,int> indices;
        vector<int> out;
        stack<int> s;
        std::reverse(nums2.begin(),nums2.end());
        for(auto n: nums2){
            while(!s.empty() && s.top() <= n )
                s.pop();
            indices[n] = s.empty() ? -1 : s.top();
            s.push(n);
        }

        for(auto n: nums1){
            out.push_back(indices[n]);
        }
        
        return out;
        
    }
};
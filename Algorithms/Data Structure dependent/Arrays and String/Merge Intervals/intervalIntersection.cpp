class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if(firstList.empty() || secondList.empty()) return vector<vector<int>>();
        auto p1 = firstList.begin(), p2 = secondList.begin();
        vector<vector<int>> out;
        while(p1 != firstList.end() && p2 != secondList.end()){
            auto i1 = *p1, i2 = *p2;
            if((i1[1] >= i2[0] && i1[0] <= i2[1]) || (i2[1] >= i1[0]) && i2[0] <= i1[1] ){
                vector<int> interval = {std::max(i1[0], i2[0]), std::min(i1[1],i2[1])};
                out.push_back(interval);
            }
            if(i1[1] < i2[1]) p1++;
            else p2++;

        }

        return out;
    }
};
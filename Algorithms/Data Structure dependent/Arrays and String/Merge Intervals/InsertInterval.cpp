class Solution {
public:
    vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval){
        vector<vector<int>> inserted;
        inserted.reserve(intervals.size()+1);
        int spot = intervals.size();
        for (int i = 0; i < intervals.size(); i++) {
            /* If next start is greater then our current start*/
            if(intervals[i][0]>=newInterval[0]){
                spot = i;
                break;
            }
        }
        /* Copy over array with the new interval*/
        copy(intervals.begin(), intervals.begin()+spot, back_inserter(inserted));
        inserted.push_back(newInterval);
        if(spot!=intervals.size()){
            copy(intervals.begin()+spot, intervals.end(), back_inserter(inserted));
        }

        return inserted;
    }

    vector<vector<int>> mergeInterval(vector<vector<int>>& intervals){
        vector<vector<int>> out;
        for (auto next: intervals){
           /*  normally current interval (out.back()) ends 
            *   before next interval starts
            */
            if(out.empty() || out.back()[1]<next[0]){ 
                out.push_back(next);
            } 
            else { 
                /* merge interval*/
                auto cur = out.back();
                out.pop_back();
                vector<int> newInterval{min(cur[0], next[0]), max(cur[1], next[1])};
                out.push_back(newInterval);
            }
        }
        return out;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto inserted=insertInterval(intervals, newInterval);
        return mergeInterval(inserted);
    }
};
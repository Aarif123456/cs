class Solution {
public:
    string shiftToBase(string& s, unordered_map<string, string>& cache){
        if(cache.find(s) == cache.end()){
            string shifted;
            int offSet = s[0] - 'a';
            for(auto &c : s){
                /* c-'a' - get letter - then take away offset and 
                 * make sure it's positive 
                 */
                int shift = ((c - 'a' - offSet) + 26) % 26;
                shifted.push_back('a'+shift);
            }
            cache[s] = shifted;
        }

        return cache[s];
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, string> cache;
        unordered_map<string, int> groupMap;
        vector<vector<string>> out;

        for(auto &s : strings){
            auto shifted = shiftToBase(s, cache);
            if(!groupMap.count(shifted)) groupMap[shifted] = groupMap.size();

            int group = groupMap[shifted];
            if(group >= out.size()) out.push_back(vector<string>());
            out[group].push_back(s);
        }

        return out;
    }
};
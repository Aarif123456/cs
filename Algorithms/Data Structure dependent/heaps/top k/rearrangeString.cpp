struct CharCount{
    char letter;
    int count;
};

class Solution {
public:
    const bool static countCompare(const CharCount* a, const CharCount* b){
        return a->count < b->count || (a->count == b->count && a->letter > b->letter);
    }

    string rearrangeString(string s, int k) {
        std::array<int, 26> count;
        count.fill(0);
        for(auto &c : s) count[c-'a']++;
        std::priority_queue<CharCount*, vector<CharCount*>, decltype(&countCompare)> pq(countCompare);
        for(int i = 0; i < 26; i++){
            if(count[i]) pq.push(new CharCount({char(i+'a'), count[i]})); 
        }

        queue<CharCount*> purgatory;
        string out;

        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            cur->count--;
            out.push_back(cur->letter);
            purgatory.push(cur);
            if(!purgatory.empty() && purgatory.size() >= k){
                auto tmp = purgatory.front(); purgatory.pop();
                if(tmp->count) pq.push(tmp);
                
            }
        }

        return out.size() == s.size()? out : "" ;
    }
};
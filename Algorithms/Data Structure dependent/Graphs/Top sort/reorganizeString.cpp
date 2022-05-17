typedef vector<int> vi; 
typedef vector<vi> vvi; 

/* For loop excluding end*/
#define FOR(i, b, c) for (int(i) = (b); (i) < (c); (i)++) 
/* For loop backward */
#define FORR(i, b, c) for (int(i) = (b); (i) >= (c); --(i)) 
/* Traverse collection */
#define TRAV(a, b) for (auto&(a) : (b)) 
/* Quick for loop */
#define REP(i, n) FOR(i, 0, n)
/* general shortcut */
#define ALL(v) v.begin(), v.end() 
#define SIZE(v) static_cast<int>(v.size())
#define NUM_LETTERS 26 
class Solution {
public:
    /* Make custom comparator */
    const bool static countCompare(const pair<char, int>& p1, const pair<char, int>& p2){
        return p1.second < p2.second;
    }
    /* Declare custom type */
    typedef priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(&countCompare)> PQ_TYPE;

    /* Create initial queue*/
    auto createInitialQueue(string S){
        PQ_TYPE pq(countCompare);
        int letterCount[NUM_LETTERS] = {};
        TRAV(c, S){
            letterCount[c-'a']++;
        }
        REP(i, NUM_LETTERS){
            if(letterCount[i]> 0){
                pq.push(make_pair('a'+i, letterCount[i]));
            }
        }
        return pq;
    }
    
    auto getNextElement(PQ_TYPE& pq ){
        auto cur = pq.top();
        pq.pop();
        char c = cur.first;
        int count = cur.second;
        count--;
        return make_pair(c, count);
    }
    string reorganizeString(string S) {
        auto pq = createInitialQueue(S);
        string out ="";
        char lastChar=0;
        while(!pq.empty()){
            auto next = getNextElement(pq);
            if(next.first == lastChar){
                if(pq.empty()) return "";
                auto nextNext = getNextElement(pq);
                out+= nextNext.first;
                if(nextNext.second>0) pq.push(nextNext);
            }
            out+= next.first;
            if(next.second>0) pq.push(next);
            lastChar = next.first;
        }
        return out;
    }
};
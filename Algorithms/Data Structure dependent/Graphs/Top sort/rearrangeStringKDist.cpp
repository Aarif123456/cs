typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<char, int> pci;

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
    const bool static pairComparator(const pci& p1, const pci& p2){
        return p1.second<p2.second || (p1.second == p2.second && p1.first >p2.first);
    } 
    typedef priority_queue<pci, vector<pci>, decltype(&pairComparator)> SPQ;
    SPQ intializePriorityQueue(string s){
        SPQ pq(pairComparator);
        int counter[NUM_LETTERS] = {};
        TRAV(c, s){
            counter[c-'a']++;
        }
        REP(i, NUM_LETTERS){
            if(counter[i]>0){{
                pq.push(make_pair(i+'a', counter[i]));
            }}
        }
        return pq;
    }
    pci getNext(SPQ& pq){
        auto cur = pq.top();
        pq.pop();
        return make_pair(cur.first, cur.second-1);
    }
    /**
     * @param s: a string
     * @param k: an integer
     * @return: a string such that the same characters are at least distance k from each other
     */
    string rearrangeString(string &s, int k) {
        auto pq = intializePriorityQueue(s);
        queue<pci> purgatory;
        string out = "";
        while(!pq.empty()){
            auto cur = getNext(pq);
            out += cur.first;
            purgatory.push(cur);
            if(purgatory.size()>=k && !purgatory.empty()){
                auto next = purgatory.front();
                purgatory.pop();
                if(next.second > 0) pq.push(next);
            }
        }
        /* If valid string return it */
        if(out.size() != s.size()) return "";
        return out;
    }
};
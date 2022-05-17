typedef vector<int> vi; 
typedef vector<vi> vvi; 
/* For loop excluding end*/
#define FOR(i, b, c) for (int(i) = (b); (i) < (c); (i)++) 
/* Traverse collection */
#define TRAV(a, b) for (auto&(a) : (b)) 
/* Quick for loop */
#define REP(i, n) FOR(i, 0, n)
// define how edges are set-up in graph
const int PARENT = 0;

class Solution {
public:
    /**
     * @param org: a permutation of the integers from 1 to n
     * @param seqs: a list of sequences
     * @return: true if it can be reconstructed only one or false
     */

    /*Initialize*/
    unordered_map<int, vi> createGraph(int numVertices, vvi& seqs){
        unordered_map<int, vi> graph;
        REP(i, numVertices){
            graph[i+1] = vi();
        }
        TRAV(seq, seqs){
            auto parent = seq[PARENT];
            FOR(i, 1, seq)
            graph[parent].push_back(child);
        }
        return graph;
    }

    /*count degree*/
    unordered_map<int, int> createDegreeCount(int numVertices, vvi& seqs){
        unordered_map<int, int> countDegrees;
        REP(i, numVertices){
            countDegrees[i+1] = 0;
        }
        TRAV(node, seqs){
            if(node.size() != 2)  continue;
            auto child = node[TO];
            countDegrees[child]++;
        }
        return countDegrees;
    }
    /*create sources queue*/
    queue<int> createSourceQueue(unordered_map<int, int>& countDegrees){
        queue<int> sourcesQueue;
        TRAV(node, countDegrees){
            auto element = node.first;
            auto degrees = node.second;
            if(degrees == 0) sourcesQueue.emplace(element);
        }
        return sourcesQueue;
    }

    /*Topological sort with a twist*/
    bool topologicalSortWithCompare(vi& org, unordered_map<int, vi>& graph, unordered_map<int, int>& countDegrees,  queue<int>& sourcesQueue){
        vi sorted;
        while(!sourcesQueue.empty()){
            if(sourcesQueue.size()>1) return false;
            auto cur = sourcesQueue.front();
            sourcesQueue.pop();
            sorted.push_back(cur);
            TRAV(child, graph[cur]){
                if((--countDegrees[child]) == 0) sourcesQueue.emplace(child);
            }
        }
        if(sorted.size() != org.size()) return false;
        REP(i, org.size()){
            if(sorted[i] != org[i]) return false;
        }
        return true;
    }
    int getMax(vector<vector<int>> &seqs){
        int maxVal = 0;
        TRAV(nums, seqs){
            if (nums.empty()) continue;
            TRAV(num, nums){ 
                maxVal = max(maxVal, num);
            }
        }
        return maxVal;
    }
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        auto maxVal = getMax(seqs);
        if(maxVal ==0 ) return org.empty();
        auto graph = createGraph(maxVal, seqs);
        auto countDegrees = createDegreeCount(maxVal, seqs);
        auto sourcesQueue = createSourceQueue(countDegrees);
        return topologicalSortWithCompare(org, graph, countDegrees, sourcesQueue);
    }
};
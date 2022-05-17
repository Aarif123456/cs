typedef unordered_set<char> uc; 
typedef vector<char> vc;
typedef vector<string> vs; 
/* For loop excluding end*/
#define FOR(i, b, c) for (int(i) = (b); (i) < (c); (i)++) 
/* Traverse collection */
#define TRAV(a, b) for (auto&(a) : (b)) 
/* Quick for loop */
#define REP(i, n) FOR(i, 0, n)
// define how edges are set-up in graph
const int FROM = 1;
const int TO = 0;

class Solution {
public:
    bool extractDependency(unordered_map<char, uc>& graph, string prevWord, string nextWord){
        REP(i, min(prevWord.length(), nextWord.length())){
            char prev = prevWord[i];
            char next = nextWord[i];
            if(prev != next){
                graph[prev].insert(next);
                return true;
            }
        }
        if(prevWord.size()> nextWord.size()) return false;
        return true;
    }
    /*Initialization: create graph */
    auto createGraph(const vs& words){
        unordered_map<char, uc> graph;
        TRAV(word, words){
            TRAV(letter, word){
                graph[letter];
            }
            if(graph.size()==26) break;
        }
        REP(i, words.size()){
            FOR(j, i, words.size()){
                if(!extractDependency(graph, words[i], words[j])) return unordered_map<char, uc> () ;
            }
        }
        return graph;
    }
    /*Count inbound degree*/
    auto countDegree(unordered_map<char, uc>& graph){
        unordered_map<char, int> degreesCount;
        TRAV(node, graph){
            degreesCount[node.first] = 0;
        }
        TRAV(node, graph){
            auto children = node.second;
            TRAV(element, children){
                degreesCount[element]++;
            }
        }
        return degreesCount;
    }
    /*Find source nodes*/
    auto createSourceQueue( unordered_map<char, int>& degreesCount){
        priority_queue<char, vc, greater<char>> sourcesQueue;
        TRAV(node, degreesCount){
            int degree = node.second;
            auto element = node.first;
            if(degree == 0) sourcesQueue.push(element);
        }
        return sourcesQueue;
    }
    /*Topological sort*/
    string topologicalSort(unordered_map<char, uc>& graph, unordered_map<char, int>& degreesCount, priority_queue<char, vc, greater<char>>& sourcesQueue){
        string ordered = "";
        while(!sourcesQueue.empty()){
            auto curNode = sourcesQueue.top();
            sourcesQueue.pop();
            ordered += curNode;
            TRAV(child, graph[curNode]){
                degreesCount[child]--;
                if(degreesCount[child] == 0) sourcesQueue.push(child);
            }
        }
        if(ordered.size() != graph.size()) return "";
        return ordered;
    }

    string alienOrder(vector<string> &words) {
        auto graph = createGraph(words);
        if(graph.empty()) return "";
        auto degreesCount = countDegree(graph);
        auto sourcesQueue = createSourceQueue(degreesCount);
        return topologicalSort(graph, degreesCount, sourcesQueue);
    }
};
typedef vector<int> vi; 
typedef vector<vi> vvi; 
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
    /*Build graph as Adjacency List*/
    unordered_map<int, vi> createAdjacencyGraph(int numVertices, const vvi& graph){
        unordered_map<int, vi> adjacencyGraph(numVertices);
        REP(i, numVertices){
            adjacencyGraph[i] = vi();
        }
        TRAV(node, graph){
            auto child = node[TO];
            auto parent = node[FROM];
            adjacencyGraph[parent].push_back(child);
        }
        return adjacencyGraph;
    }
    /*Count how many parent nodes each node has */
    unordered_map<int, int> createDegreeCount(int numVertices, const vvi& graph){
        unordered_map<int, int> degreeCount(numVertices);
        REP(i, numVertices){
            degreeCount[i] = 0;
        }
        /*Every time a node is a child (has a prerequisite increase its degree)*/
        TRAV(node, graph){
            auto child = node[TO];
            degreeCount[child]++;
        }
        return degreeCount;
    }

    /*Create source queue*/
    queue<int> createSourceQueue(const unordered_map<int, int> degreeCount){
        queue<int> sourcesQueue;
        TRAV(count, degreeCount){
            auto element = count.first;
            auto degree = count.second;
            if(degree == 0)  sourcesQueue.emplace(element);
        }
        return sourcesQueue;
    }
    /* Top sort*/
    vi topologicalSort(int numVertices, unordered_map<int, vi>& adjacencyGraph,  unordered_map<int, int>& degreeCount, queue<int> sourcesQueue ){
        vi sortedList;
        while(!sourcesQueue.empty()){
            auto curElement = sourcesQueue.front();
            sourcesQueue.pop();
            sortedList.push_back(curElement);
            TRAV(course, adjacencyGraph[curElement]){
                degreeCount[course]--;
                if(degreeCount[course] == 0) sourcesQueue.emplace(course);
            }
        }
        if(sortedList.size() != numVertices) return vi();
        return sortedList;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        auto adjacencyGraph = createAdjacencyGraph(numCourses, prerequisites);
        auto degreeCount = createDegreeCount(numCourses, prerequisites);
        auto sourcesQueue = createSourceQueue(degreeCount);
        auto courses = topologicalSort(numCourses,adjacencyGraph, degreeCount, sourcesQueue);
        return courses;
    }
};
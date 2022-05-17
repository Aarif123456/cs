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
    /*Initialization: Adjacency list to represent graph */
    unordered_map<int, vi> createAdjacencyList(int numVertices, const vvi& graph){
        unordered_map<int, vi> adjacencyList(numVertices);
        REP(i, numVertices){
            adjacencyList[i] = vi();
        }
        TRAV(node, graph){
            auto child = node[TO];
            auto parent = node[FROM];
            adjacencyList[parent].push_back(child);
        }
        return adjacencyList;
    }

    /*Count degree */
    unordered_map<int, int> createDegreeCountMap(int numVertices, const vvi& graph){
        unordered_map<int, int> degreeCount(numVertices);
        REP(i, numVertices){
            degreeCount[i] = 0;
        }
        TRAV(node, graph){
            auto child = node[TO];
            degreeCount[child]++;
        }
        return degreeCount;
    }

    /* Store our source nodes. The nodes with no parents */
    queue<int> createSourceQueue(int numVertices, const unordered_map<int, int> & degreeCount){
        queue<int> sourceQueue;
        TRAV(count, degreeCount){
            auto element = count.first;
            auto numParents = count.second;
            if (numParents == 0){
                sourceQueue.emplace(element);
            }
        }
        return sourceQueue;
    }

    vi topSort(int numVertices, unordered_map<int, vi>& adjacencyList,  unordered_map<int, int>& degreeCount, queue<int>& sourceQueue){
        vi output;
        while(!sourceQueue.empty()){
            /* Get our current node and add to our output */
            auto curCourse = sourceQueue.front();
            sourceQueue.pop();
            output.push_back(curCourse);
            TRAV(course, adjacencyList[curCourse]){
                degreeCount[course]--;
                if(degreeCount[course] == 0){
                    sourceQueue.emplace(course);
                }
            }
        }
        return output;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        auto adjacencyList = createAdjacencyList(numCourses, prerequisites);
        auto degreeCount = createDegreeCountMap(numCourses, prerequisites);

        /* Create list of source nodes*/
        auto sourceQueue = createSourceQueue(numCourses, degreeCount);
        auto courseList = topSort(numCourses, adjacencyList, degreeCount, sourceQueue);
        
        return courseList.size() == numCourses;
    }
};
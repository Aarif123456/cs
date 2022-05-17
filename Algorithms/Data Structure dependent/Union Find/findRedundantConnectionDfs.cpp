typedef vector<int> vi; 
typedef vector<vi> vvi;
typedef std::unordered_map<int, unordered_set<int>> adj_graph;

class Solution {
public:
    /* Check if we have an edge connecting our two nodes */
    bool dfs(vvi& edges, adj_graph& graphSoFar, unordered_set<int>& visited, int x, int y){
        if(x == y) return true;
        for(auto &start : graphSoFar[x]){
            if(visited.find(start) == visited.end()){
                visited.insert(start);
                if(start == y) return true;
                /* try to reach y through some reachable node */
                if(dfs(edges, graphSoFar, visited, start, y)) return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        adj_graph graphSoFar;
        for(auto &edge : edges){
            graphSoFar[edge[0]] = unordered_set<int>();
            graphSoFar[edge[1]] = unordered_set<int>();
        }

        for(auto &edge : edges){
            unordered_set<int> visited;
            /* check if edge is redundant */
            if(dfs(edges, graphSoFar, visited, edge[0], edge[1])) return edge;
            graphSoFar[edge[0]].insert(edge[1]);
            graphSoFar[edge[1]].insert(edge[0]);
        }

        /* We were supposed to have redundant edge*/
        assert(false && "We were supposed to have atleast one redundant edge");
    }
};
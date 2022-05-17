typedef unordered_set<char> uc;
typedef unordered_map<char, uc> adj_graph;
typedef string::iterator s_it;
class Solution {
public:
    /** Top Sort
     * 1. Create graph
     * 2. Count indegree
     * 3. create source queue
     * 4. Do normal BFS
     */
    bitset<26> seen;

    bool extractDependency(adj_graph& graph, s_it s1, s_it e1, s_it s2, s_it e2){
        while(s1 != e1 && s2 != e2){
            if(*s1 != *s2){
                graph[*s1].insert(*s2);
                return true;
            }
            s1++; s2++;
        }
        /* second string should have reached ending if all the same*/
        return s1 == e1;
    }
    bitset<26> getSeen(vector<string>& words){
        seen.reset();
        for(auto &word : words){
            for(auto &c : word){
                seen[c-'a'] = true;
            }
        }

        return seen;
    }
    auto createGraph(vector<string>& words){
        adj_graph graph;
        for(auto i='a'; i<='z'; i++){
            if(seen[i-'a']) graph[i];
        }
        for(int i = 0; i < words.size(); i++){
            for(int j = i+1; j < words.size(); j++){
                /* handle invalid entry - where word is longer*/
                if(!extractDependency(graph, words[i].begin(), words[i].end(), words[j].begin(), words[j].end())) 
                    return unordered_map<char, uc> () ;
            }
        }
        // cout << "real" <<endl;
        return graph;
    }
    unordered_map<char, int> countDegrees(adj_graph& graph){
        unordered_map<char, int> degreesCount;
        for(auto i='a'; i<='z'; i++) if(seen[i-'a']) degreesCount[i] = 0;
        for(auto parent='a'; parent<='z'; parent++){
            if(!seen[parent-'a']) continue;
            for(auto &child : graph[parent]){
                // cout << parent << ":" << child <<endl;
                degreesCount[child]++;
            }
        }

        return degreesCount;
    }

    queue<char> createSourceQueue(unordered_map<char, int>& degreesCount){
        queue<char> sourcesQueue;
        for(auto i='a'; i<='z'; i++){
            if(!seen[i-'a']) continue;
            // cout <<i <<":" <<degreesCount[i];
            if(!degreesCount[i]) sourcesQueue.push(i);
        }
        // cout << endl;

        return sourcesQueue;
    }

    string topologicalSort(adj_graph& graph, unordered_map<char, int>& degreesCount, queue<char>& sourcesQueue){
        string ordered = "";
        while(!sourcesQueue.empty()){
            auto cur = sourcesQueue.front(); sourcesQueue.pop();
            ordered.push_back(cur);
            for(auto &child : graph[cur]){
                degreesCount[child]--;
                if(!degreesCount[child]) sourcesQueue.push(child);
            }
        }

        return ordered.length() == seen.count() ? ordered : "";
    }

    string alienOrder(vector<string>& words) {
        seen = getSeen(words);
        auto graph = createGraph(words);
        // cout << "graph made" << endl;
        if(graph.empty()) return "";
        auto degreesCount = countDegrees(graph);
        // cout << "degrees counted" << endl;
        auto sourcesQueue = createSourceQueue(degreesCount);
        // cout << "top sort:" <<sourcesQueue.size();
        return topologicalSort(graph, degreesCount, sourcesQueue) ;      
    }
};
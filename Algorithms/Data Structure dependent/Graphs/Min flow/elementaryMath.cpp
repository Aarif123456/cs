#include <iostream>
#include <vector>
#include <ctgmath>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vii;
typedef vector<bool> vb;
typedef vector<vb> vib;
typedef vector<pair<ll,ll>> vip;

vii adj;
unordered_map<ll, int> numberMapper;

// Shortcut
#define rep(i, a, b) for(int i = a; i < (b); i++)
#define trav(a, x) for(auto a : x)

// set up for min-max
#define SOURCE 0
#define SINK 1
#define PAIR_NUM(x) (2+x)
#define ANSWER_NUM(x) ((int) pairs.size()+numberMapper[x]+2)
#define GET_PAIR_NUM(x) (x-2)
#define GET_ANS_NUM(x) (x-(int) pairs.size()-2)
#define sz ((int)pairs.size()+numbers.size()+2)
#define addEdge(source, destination)   {\
                                        adj[source].push_back(destination); \
                                        adj[destination].push_back(source);\
                                        graph[source][destination]=true;       \
                                        }


// Find path from source to sink and get minFlow - return 0 if there is no path
bool BFS (const vib& capacityGraph, vi& parent){
    fill(parent.begin(), parent.end(), -1);
    parent[SOURCE] = -2;
    vb visited(parent.size());
    fill(visited.begin(), visited.end(), false);
    // Create a visited array and mark all vertices as not visited

    // Create a queue, enqueue source vertex and mark source vertex as visited
    queue<int> q;
    q.push(SOURCE);
    visited[SOURCE]=true;

    // Standard BFS Loop
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        trav(next, adj[cur]) {
            if (!visited[next] && capacityGraph[cur][next])
            {
                parent[next] = cur;
                visited[next]=true;
                q.push(next);
            }
        }
    }

    return visited[SINK];
}

/* Debug function */
void printGraph(vib const& graph){
    trav(node, graph){
        for(auto n: node){
            cout << n << " ";
        }
        cout <<endl;
    }
     cout <<endl;
}
/* Solving function */
auto edmondKarp(vib& capacityGraph, int numVertices, int minFlow) {
    int flow = 0;
   vi parent(numVertices);
//   printGraph(capacityGraph);
   while((BFS(capacityGraph, parent))){
       int cur = SINK;
       while (cur != SOURCE) {
            int prev = parent[cur];
            capacityGraph[prev][cur] = false;
            capacityGraph[cur][prev] = true;
            cur = prev;
       }
       flow++;
//       printGraph(capacityGraph);
   }
    if(flow<minFlow){
        capacityGraph.clear();
    }
//     cout << "flow "<< flow <<endl;
     return capacityGraph;
}

auto createInitialCapacityGraph(const vip& pairs, const vl& numbers) {
    // make graph where row 0 is our source and row 1 is our sink
    // then we will set our source to go to one pair operation
    // then we will go through our trains and see what they are sending to our sink -
    vib graph(sz);
    adj.resize(sz);
    for(auto & i : graph){
        i.resize(sz);
    }
    rep(i, 0, pairs.size()){
        auto p = pairs[i];
        addEdge(SOURCE, PAIR_NUM(i))
        addEdge(PAIR_NUM(i), ANSWER_NUM(p.first+p.second))
        addEdge(PAIR_NUM(i), ANSWER_NUM(p.first-p.second))
        addEdge(PAIR_NUM(i), ANSWER_NUM(p.first*p.second))
    }

    trav(i, numbers){
        addEdge(ANSWER_NUM(i), SINK)
    }

    return graph;
}

auto createPossibleOutputs(const vip& pairs) {
    vl numbers;
    trav(p, pairs){
        auto sum = p.first + p.second;
        auto diff = p.first - p.second;
        auto prod = p.first * p.second;
        if(numberMapper.count(sum)==0){
            numberMapper.emplace(sum, numbers.size());
            numbers.push_back(sum);
        }
        if(numberMapper.count(diff)==0){
            numberMapper.emplace(diff, numbers.size());
            numbers.push_back(diff);
        }
        if(numberMapper.count(prod)==0){
            numberMapper.emplace(prod, numbers.size());
            numbers.push_back(prod);
        }
    }
    return numbers;
}

void printOperation(const pair<ll, ll> &p, const ll &i) {
    cout << p.first;
    if(p.first+p.second==i){
         cout << " + " ;
    }
    else if(p.first-p.second==i){
        cout << " - " ;
    }
    else if(p.first*p.second==i){
        cout << " * " ;
    }
    else{
        cout << " ERROR ";
    }
    cout << p.second << " = " << i << endl;
}

void printOutput(const vib& flowGraph, const vip& pairs, const vl& numbers) {
    // go through sink to figure out what answers we have
    rep(pairNum,2,  pairs.size()+2){
        rep(ans,pairs.size(),  flowGraph.size()){
        if(flowGraph[SINK][ans]){
                if(flowGraph[ans][pairNum]){
                    printOperation(pairs[GET_PAIR_NUM(pairNum)], numbers[GET_ANS_NUM(ans)]);
                }
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    vip pairs(n);
    rep(i, 0, n) {
        cin >> pairs[i].first >> pairs[i].second;
    }
    auto numbers = createPossibleOutputs(pairs);
//    trav(k, numbers){
//        cout << k << " ";
//    }
//    cout <<endl;
    auto capacityGraph =  createInitialCapacityGraph(pairs, numbers);
    auto flowGraph = edmondKarp(capacityGraph, sz, n);
    if(flowGraph.empty()){
        cout << "impossible" << endl;
    }
    else{
        printOutput(flowGraph, pairs, numbers);
    }
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
 * Complete the 'bestTrio' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts UNWEIGHTED_INTEGER_GRAPH friends as parameter.
 */

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. An edge exists between <name>_from[i] and <name>_to[i].
 *
 */
typedef set<int> Node;

int bestTrio(int friends_nodes, vector<int> friends_from, vector<int> friends_to){
    vector<Node> nodes(friends_nodes+1);
    auto from = friends_from.begin(), to = friends_to.begin();
    for(; from !=  friends_from.end() ; from++, to++){
        nodes[*from].insert(*to);
        nodes[*to].insert(*from);
    }
    
    int minFriendNum = INT_MAX;
    for(int i=1; i<=friends_nodes; i++){
        for(auto j: nodes[i]){
            vector<int> commonBff;
            auto s1 = nodes[i], s2 = nodes[j];
            std::set_intersection(s1.begin(),s1.end(),s2.begin(), s2.end(), std::back_inserter(commonBff));
            for(auto k: commonBff){
                int friendNum = s1.size()+s2.size()+nodes[k].size()-6;
                minFriendNum = std::min(minFriendNum, friendNum);
            }
        }
    }
    
    return minFriendNum == INT_MAX ? -1 : minFriendNum;
}
int main()
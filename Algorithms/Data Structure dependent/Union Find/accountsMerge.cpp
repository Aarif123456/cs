struct Node{
    string data;
    /* Empty rank means we are our own parent */
    Node* parent;
    int rank = 0;
};
typedef std::unordered_map<string, Node*> union_find;

auto makeSet(union_find& unionFind, string& data){
    /* If we don't have set then make one */
    if(unionFind.count(data) == 0) unionFind[data] = new Node{data, nullptr, 0};

    return unionFind[data];
}

auto find(Node* p){
    if(!p->parent) return p;
    return p->parent = find(p->parent);
}

bool unifySet(union_find& unionFind, string& d1, string& d2){
    auto n1 = unionFind[d1], n2 = unionFind[d2];
    auto p1 = find(n1), p2 = find(n2);
    if(p1 == p2) return false;

    if(p1->rank == p2->rank) p1->rank++;
    if(p1->rank > p2->rank) p2->parent = p1;
    else p1->parent = p2;

    return true;
}

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        union_find unionFind;
        for(auto &emailInfo : accounts){
            auto ogEmail = emailInfo[1];
            for(int i = 1; i < emailInfo.size(); i++){
                auto email = emailInfo[i];
                makeSet(unionFind, email);
                unifySet(unionFind, ogEmail, email);
            }
        }

        unordered_map<string, int> names;
        vector<vector<string>> out;
        for(auto &emailInfo : accounts){
            auto name = emailInfo[0];
            auto rootEmail = find(unionFind[emailInfo[1]])->data;
            /*If new node - then create new entry */
            if(names.find(rootEmail) == names.end()){
                names[rootEmail] = out.size();
                out.push_back({name});
            }
        }

        for(auto &nodePair: unionFind){
            auto node = nodePair.second;
            auto group = names[find(node)->data];
            out[group].push_back(node->data);
        }

        for(auto &email : out) std::sort(email.begin()+1, email.end());

        return out;

    }
};
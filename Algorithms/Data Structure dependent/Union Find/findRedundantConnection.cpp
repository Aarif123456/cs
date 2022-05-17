struct Node{
    int data;
    /* empty pointer represent pointer to self */
    Node* parent;
    int rank = 0;
};
typedef std::unordered_map<int, Node*> unionFind;

bool makeSet(unionFind& unFind, int data){
    if(unFind.count(data)) return false;
    auto node = new Node{data, nullptr, 0};
    unFind[data] = node;

    return true;
}

/* We use path compression - make parent the node without any parent */
Node* find(Node* p){
  if (!p->parent) return p;
  return p->parent = find(p->parent);
}

/* We use union rank: make parent element with bigger rank(depth) */
bool unionSet(unionFind& unFind, int d1, int d2){
    auto node1 = unFind[d1], node2 = unFind[d2];
    auto p1 = find(node1), p2 = find(node2);
    /* Same set do nothing */
    if(p1 == p2) return false;
    /* Check for same rank - and increment rank */
    if(p1->rank == p2->rank) p1->rank += 1;

    /* Now, just make node with bigger node parent */
    if(p1->rank > p2->rank) p2->parent = p1;
    else p1->parent = p2;

    return true;

}

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unionFind unFind;
        /* Set up union find */
        for(auto &edge : edges){
            makeSet(unFind, edge[0]);
            makeSet(unFind, edge[1]);
        }

        /* We try to combine graphs - if same graph - we found redundant */
        for(auto &edge : edges)
            if(!unionSet(unFind, edge[0], edge[1])) return edge;

         /* We were supposed to have redundant edge*/
        assert(false && "We were supposed to have atleast one redundant edge");
    }
};
typedef vector<int> vi;
typedef vector<vi> vvi;
struct Node{
    TreeNode* node;
    int x, y;
};

class Solution {
public:
    const bool static treeComp(Node pa, Node pb){
        return (pa.y > pb.y) || (pa.y == pb.y && pa.node->val > pb.node->val);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        std::priority_queue<Node, vector<Node>, decltype(&treeComp) >  pq(treeComp);
        /* Track boundary */
        int minX = 0, maxX = 0;
        /* go through tree and add to min heap */
        std::queue<Node> q;
        q.push({root, 0, 0});
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            pq.push(cur);
            auto x = cur.x, y = cur.y;
            auto curRoot = cur.node;
            minX = std::min(minX, x);
            maxX = std::max(maxX, x);
            if(curRoot->left) q.push({curRoot->left,x-1,y+1});
            if(curRoot->right) q.push({curRoot->right,x+1,y+1});
        }

        /* offset left elements */
        auto offset = std::abs(minX);
        vvi ans(offset+maxX+1, vi());

        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            auto x = cur.x;
            auto curRoot = cur.node;
            ans[x+offset].push_back(curRoot->val);
        }

        return ans;

    }
};
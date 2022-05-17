/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */


class Solution {
public:
    int getDepth(ParentTreeNode * cur, int depth = 0){
        if (cur == nullptr || cur->parent == nullptr) return depth;
        return getDepth(cur->parent, depth +1);
    }
    /*
     * @param root: The root of the tree
     * @param A: node in the tree
     * @param B: node in the tree
     * @return: The lowest common ancestor of A and B
     */
    ParentTreeNode * lowestCommonAncestorII(ParentTreeNode * root, ParentTreeNode * A, ParentTreeNode * B) {
        int depth1 = getDepth(A);
        int depth2 = getDepth(B);
        while(depth1 > depth2){
            depth1--;
            A = A->parent;
        }

        while(depth2 > depth1){
            depth2--;
            B = B->parent;
        }

        while(A != B){
            A = A->parent;
            B = B->parent;
        }

        return A;
    }
};
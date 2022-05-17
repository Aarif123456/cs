inline std::ostream& operator <<(std::ostream &out, const TreeNode* root){
    if(!root) return out << "#";
    char sep = ',';
    out << root->val;
    out << sep << root->left;
    out << sep << root->right;

    return out;
}

inline std::istream& operator >>(std::istream& ins, TreeNode* &root){
    string s = "";
    char c;
    root = nullptr;
    while(ins >> c && c != ',') s.push_back(c);

    if(s != "#" && !s.empty()){
        root = new TreeNode(stoi(s));
        ins >> root->left;
        ins >> root->right;
    }

    return ins;
}

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        out << root;

        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ins(data);
        TreeNode* root;
        ins >> root;

        return root;
    }
};


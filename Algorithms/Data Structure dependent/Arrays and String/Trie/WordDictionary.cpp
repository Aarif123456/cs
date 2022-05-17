#define NUM_LETTERS 26
struct Trie{
    int pos = 0;
    bool word = false;
    array<Trie*, 26> next{};
};

void updateTrie(Trie* root, string word){
    for(auto &c : word){
        if(root->next[c-'a'] == nullptr) {
            root->next[c-'a'] = new Trie();
            root->next[c-'a']->pos = root->pos+1;
        }
        root = root->next[c-'a'];
    }
    root->word = true;
}

class WordDictionary {
public:
    Trie root;
    WordDictionary() {
    }
    
    void addWord(string word) {
        updateTrie(&root, word);
    }
    
    bool search(string word) {
        std::stack<Trie*> stack;
        stack.push(&root);
        while(!stack.empty()){
            auto cur = stack.top(); stack.pop();
            auto pos = cur->pos;
            if(pos == word.length()){
                if(cur->word) return true;
            }
            else{
                if(word[pos] == '.'){
                    for(auto next : cur->next){
                        if(next != nullptr) stack.push(next);
                    }
                }
                else if(cur->next[word[pos] - 'a'] != nullptr) stack.push(cur->next[word[pos] - 'a']);
            }
        }

        return false;
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
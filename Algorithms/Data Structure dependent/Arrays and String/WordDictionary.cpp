#define NUM_LETTERS 26

class WordDictionary {
public:
    /* Idea: we can track the characters we have seen at each position and 
     * then check for mask
     * FAILED: 
     * ["WordDictionary","addWord","addWord","addWord","addWord","search","search","addWord","search","search","search","search","search","search"]
    [[],["at"],["and"],["an"],["add"],["a"],[".at"],["bat"],[".at"],["an."],["a.d."],["b."],["a.d"],["."]]

    "WordDictionary"
    addWord(at) => null
    addWord(and) => null
    addWord(an) => null
    addWord(add) => null
    addWord(bat) => null
    search(b.) => true - should be false
    search(a.d) => true
    search(.) => false
     */
    vector<bitset<NUM_LETTERS+1>> mask;

    /** Initialize your data structure here. */
    WordDictionary(int maxLength=501) {
        mask = vector<bitset<NUM_LETTERS+1>>(maxLength);
    }
    
    void addWord(string word) {
        int i = 0;
        for(int i = 0; i < word.length(); i++){
            int letterIndex = word[i] - 'a';
            mask[i][letterIndex] = true;
        }

        /* track if word ended */
        mask[word.length()][26] = true;
    }
    
    bool search(string word) {
        for(int i = 0; i < word.length(); i++){
            char c = word[i];
            if(c == '.'){
                if(mask[i].none()) return false;
            }
            else{
                if(!mask[i][c-'a']) return false;
            }
        }
        /* If we have a word that ends return true */
        return mask[word.length()][26] ;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
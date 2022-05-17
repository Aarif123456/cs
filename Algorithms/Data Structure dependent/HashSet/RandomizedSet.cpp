class RandomizedSet {
public:
    /* Track how many active elements you have */
    unordered_map<int, int> contains;
    vector<int> elements;
    RandomizedSet() {
    }
    
    /* If new element insert 
     * if our array has deleted elements overwrite
     * otherwise normal insert
     */
    bool insert(int val) {
        if(contains.find(val) != contains.end()) return false;
        contains[val] = elements.size();
        elements.push_back(val);

        return true;
    }
    
    bool remove(int val) {
        if(contains.find(val) == contains.end()) return false;
        int i = contains[val];
        /* Move element to back and remove */
        if(i != elements.size()-1){
            std::swap(elements[i], elements[elements.size()-1]);
            contains[elements[i]] = i;
        }
        /* Remove last element from set */
        elements.pop_back();
        contains.erase(val);

        return true;
    }
    
    int getRandom() {
        return elements[std::rand() % elements.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
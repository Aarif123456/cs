type TrieNode struct {
    done bool
    next map[int]*TrieNode
}

type Trie struct {
    root *TrieNode
}


func newTrieNode() *TrieNode {
    return &TrieNode{
            false,
            make(map[int]*TrieNode),
        }
}

func Constructor() Trie {
    return Trie{
        newTrieNode(),
    }
}


func (this *Trie) Insert(word string)  {
    cur := this.root 
    for _, c := range(word){
        if _, ok := cur.next[int(c)]; !ok {
            cur.next[int(c)] = newTrieNode()
        }
        cur = cur.next[int(c)]
    }
    cur.done = true
}


func (this *Trie) Search(word string) bool {
    cur := this.root 
    for _, c := range(word){
        if _, ok := cur.next[int(c)]; !ok {
            return false
        }
        cur = cur.next[int(c)]
    }

    return cur.done
}


func (this *Trie) StartsWith(prefix string) bool {
    cur := this.root 
    for _, c := range(prefix){
        if _, ok := cur.next[int(c)]; !ok {
            return false
        }
        cur = cur.next[int(c)]
    }

    return true
}


/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
#define MAX_NUMBER 500

class Solution {
public:
    bool recursiveHelper(string &s,  int start, unordered_set<string> words, bitset<MAX_NUMBER> &visited, bitset<MAX_NUMBER> &mem){
        if(start==s.length()) return true;
        if(visited[start]) return mem[start];
        visited[start] = true;
        string sub;
        for (auto i=start; i<=s.length(); i++){
            sub += s[i];
            if(words.count(sub) > 0 && recursiveHelper(s, i+1, words, visited, mem)) return mem[start] = true;
        }

        return mem[start] = false;
    }
    /* DP Explanation:
     * brute-force: can go to each position multiple times, but if we already 
     * tried every substring from that point onwards we don't need to check it again 
     * so, if we track what we already explored and the answer at the explored state
     */
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        bitset<MAX_NUMBER> visited;
        bitset<MAX_NUMBER> mem;

        return recursiveHelper(s, 0, words, visited, mem);
    }
};

#define MAX_LENGTH 301

class Solution {
public:
    bool wordBreak(string &s, unordered_set<string>& wordDict, std::bitset<MAX_LENGTH>& valid, std::bitset<MAX_LENGTH>& visited, int pos = 0){
        if(pos == s.length()) return valid[pos] = true;
        if(visited[pos]) return valid[pos];
        visited[pos] = true;
        string cur = "";
        for(int i = pos; i < s.length() && !valid[pos]; i++){
            cur.push_back(s[i]);
            if(wordDict.find(cur) != wordDict.end()){
                // cout << cur << endl;
                valid[pos] = wordBreak(s, wordDict, valid, visited, i+1);
            }
        }

        return valid[pos];

    }
    bool wordBreak(string s, vector<string>& words) {
        std::bitset<MAX_LENGTH> valid, visited;
        unordered_set<string> wordDict(words.begin(), words.end());
        return wordBreak(s, wordDict, valid, visited, 0);

    }
};
#define MAX_VAL 1001
typedef vector<string> vs;
typedef vector<vs> vvs;

class Solution {
public:
    std::bitset<MAX_VAL> visited;
    vvs memo;

    vs recursiveHelper(string s, unordered_set<string>& wordDict, int start = 0){
        // cout << "start:" << start << endl;
        if(start >= s.length()) return {""};

        if(visited[start]) return memo[start];
        visited[start] = true;
        string sub = "";
        for(auto i = start; i<s.length(); ++i){
            sub.push_back(s[i]);
            // cout <<sub << endl;
            if(wordDict.find(sub) != wordDict.end()){
                auto listToCombine = recursiveHelper(s, wordDict, i+1);
                for(auto &word : listToCombine){
                    auto addWord = sub;
                    if(word.length()) addWord += " " + word;
                    memo[start].push_back(addWord);    
                }
            }
        }

        return memo[start];
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        visited = std::bitset<MAX_VAL>(0);
        memo = vvs(s.length(), vs{});
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        return recursiveHelper(s, words);
    }
};
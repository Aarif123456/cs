typedef pair<char, int> pci;
#define NUM_LETTERS 26

class Solution {
public:
    /* Key intuition: If a character will appear again we can remove it 
     * if we find a letter smaller than it. By always removing larger letter we are guaranteed
     * to obtain lexicographical order
     */
    string removeDuplicateLetters(string s) {
        std::bitset<NUM_LETTERS> visited;
        std::array<int, NUM_LETTERS> count;
        count.fill(0);

        for(auto c: s){
            count[c-'a']++;
        }

        std::stack<char> mono;
        for (int i = 0; i < s.length(); i++){
            auto c = s[i];
            count[c - 'a']--;
            if(visited[c - 'a']) continue;
            visited[c - 'a'] = true;
            while(!mono.empty() && mono.top() > c && count[mono.top() - 'a'] > 0){
                visited[mono.top() - 'a'] = false;
                mono.pop();
            }

            mono.push(c);
        }

        std::string out(mono.size(), '0');
        for (int i = out.length()-1; i >= 0; i--){
            out[i] = mono.top(); mono.pop();
        }

        return out;
    }
};
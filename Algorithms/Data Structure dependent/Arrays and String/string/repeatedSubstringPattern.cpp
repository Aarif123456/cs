class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i = 1, j = 0, n = s.length();
        vector<int> dp(n+1, 0);

        while(i < n){
            if(s[i] == s[j]) dp[++i] = ++j;
            else if(j == 0) i++;
            else j = dp[j]; // Reset to previous
        }

        return dp[n] && (dp[n] % (n-dp[n])) == 0;
    }
};
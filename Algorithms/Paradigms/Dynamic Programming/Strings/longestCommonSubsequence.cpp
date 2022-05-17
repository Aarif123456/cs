typedef vector<int> vi; 

class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        if(a.length() > b.length()) return longestCommonSubsequence(b, a);

        int n = a.length(), cur, pre;
        vi dp(n+1, 0);
        for(auto c: b){
            pre=0;
            for(auto i=1; i<=n; i++){
                if(c == a[i-1]) pre += 1; 
                cur = dp[i];
                dp[i] = max({dp[i], dp[i-1], pre});
                pre = cur;
            }
        }
        
        return dp[n];
    }
};

// Incorrect: fails 
"ccbcb"
"bccb"
// typedef vector<int> vi; 

// class Solution {
// public:
//     int longestCommonSubsequence(string a, string b) {
//         if(a.length() > b.length()) return longestCommonSubsequence(b, a);

//         int n = a.length();
//         vi dp(n+1, 0);
//         for(auto c: b){
//             for(auto i=1; i<=n; i++){
//                 if(c == a[i-1] && dp[i] == dp[i-1])
//                     dp[i] += 1; 
//                 dp[i] = max(dp[i], dp[i-1]);
//                 cout << c  <<"," << a[i-1] <<":"<< dp[i] << " ";
//             }
//             cout << endl;
//         }
        
//         return dp[n];
//     }
// };
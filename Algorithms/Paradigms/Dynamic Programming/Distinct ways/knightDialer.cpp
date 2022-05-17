typedef vector<long long> vi; 
typedef vector<vi> vvi; 
#define MOD (static_cast<long long>(1E9)+7)
class Solution {
public:
    int knightDialer(int n) {
        vvi dp(n+1, vi(10, 1));
        vvi jumpTo = {{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};

        for(int i = 2; i <= n; i++){
            for(int j = 0; j < dp[i].size(); j++){
                long long sum = 0;
                for(int next: jumpTo[j]){
                    sum += dp[i-1][next];
                    sum %= MOD;
                }
                dp[i][j] = sum;
            }
        }
        return std::accumulate(dp[n].begin(), dp[n].end(), 0LL) % MOD;
    }
};
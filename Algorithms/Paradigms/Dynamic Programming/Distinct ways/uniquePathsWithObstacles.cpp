typedef vector<int> vi;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vi dp(n, 0);
        dp[0] = 1;
        for(auto &row: obstacleGrid){
            if(row[0]) dp[0] = 0;
            for(int j = 1; j < n; j++){
                /* If not an obstacle then we try to find ways */
                if(!row[j]) dp[j] += dp[j-1];
                else dp[j] = 0;
            }
        }

        return dp[n-1];
    }
};
# idea find longest common subsequence - those character don't have to be replaced
# then we can just add or delete to fill in some of the missing
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        INVALID = m+n+1
        dp = [[j for j in range(n+1)] for i in range(m+1)]
        for i, c1 in enumerate(word1):
            dp[i+1][0] = i+1
            for j, c2 in enumerate(word2):
                if c1 == c2:
                    dp[i+1][j+1] = dp[i][j]
                else:
                    # Case 1: replace one char
                    # Case 2: delete from word1
                    # Case 3: delete from word2
                    dp[i+1][j+1] = min(dp[i][j], dp[i][j+1], dp[i+1][j]) + 1

        return dp[-1][-1]
        
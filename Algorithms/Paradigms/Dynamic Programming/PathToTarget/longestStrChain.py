class Solution:
    def longestStrChain(self, wordList: List[str]) -> int:
        longestPath = {}
        wordSet = set(wordList)
        maxWordSize = max([len(word) for word in wordList])
        def dfs(word) -> int:
            nonlocal wordSet, longestPath, maxWordSize
            if word in longestPath: return longestPath[word]
            bestSize, n = 1, len(word)
            if n == maxWordSize: 
                longestPath[word] = 1
                return longestPath[word]
            # print(f"curWord:{word}")
            for i in range(n+1):
                for c in range(26):
                    nextWord = f"{word[:i]}{chr(c + ord('a'))}{word[i:]}"
                    # print(f"nextWord:{nextWord}")
                    if nextWord in wordSet:
                        bestSize = max(bestSize, 1 + dfs(nextWord))

            longestPath[word] = bestSize 
            return bestSize
        best = 0
        for word in wordList:
            best = max(best, dfs(word))
        # print(longestPath)
        return best
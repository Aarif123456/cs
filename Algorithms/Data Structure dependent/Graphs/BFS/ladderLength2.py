from queue import SimpleQueue

class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        # go backward and find path to first word
        def getPath(parents, start, end):
            cur, out = start, []
            while cur:
                out.append(cur)
                cur = parents[cur]
            return out[::-1]

        words = set(wordList)
        q, parents = SimpleQueue(), {}
        q.put_nowait((beginWord, "", 1))
        goalDist, ans = math.inf, []

        while not q.empty():
            cur, par, d = q.get_nowait()
            if d > goalDist or d > len(words): continue
            parents[cur] = par
            if cur == endWord: 
                goalDist = min(goalDist, d)
                ans.append(getPath(parents, endWord, beginWord))
            for i, c in enumerate(cur):
                x = ord(c) - ord('a')
                wordStart, wordEnd = cur[:i], cur[i+1:]
                for j in range(1, 26):
                    val = chr((x+j+26) % 26 + ord('a'))
                    nextWord = f"{wordStart}{val}{wordEnd}"
                    if nextWord == par: continue
                    if nextWord in words:
                        q.put_nowait((nextWord, cur, d+1))

        return ans



        
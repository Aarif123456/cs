from collections import defaultdict
class Trie:
    def __init__(self, count = 0):
        self.possible = [None] * 26 
        self.count = count 

    def putChar(self, c: chr):
        i = ord(c) - ord('a')
        if self.possible[i] is None:
            self.possible[i] = Trie()

        return self.possible[i] 

    def getChar(self, c: chr):
        i = ord(c) - ord('a')
        return self.possible[i]



class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        q = defaultdict(list)
        for it in map(iter, words):
            q[next(it)].append(it)
        for c in s:
            # pop item if it exists else get nothing
            for it in q.pop(c, []):
                q[next(it, None)].append(it)
                
        return len(q[None])







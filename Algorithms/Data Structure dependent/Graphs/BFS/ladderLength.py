from collections import defaultdict
from copy import deepcopy
from queue import SimpleQueue

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        assert(len(beginWord) == len(endWord))
        k = len(beginWord)

        # O(n*26*k)
        def makeGraph(wordSet):
            graph = defaultdict(set)
            for word in wordSet:
                for i, c in enumerate(word):
                    x = ord(c) - ord('a')
                    wordStart, wordEnd = word[:i], word[i+1:]
                    for j in range(1, 26):
                        val = chr((x+j)%26+ord('a'))
                        curWord = wordStart + val + wordEnd
                        if curWord in wordSet:
                            graph[word].add(curWord)
            return graph

        wordList.append(beginWord)
        wordSet = set(wordList)
        graph = makeGraph(wordSet)
        # print(graph)
        if len(graph[endWord]) == 0: return 0

        # BFS
        q = SimpleQueue()
        q.put_nowait((beginWord, 1))
        visited = set()
        while not q.empty():
            curWord, dist = q.get_nowait()
            if curWord in visited: continue
            visited.add(curWord)
            if curWord == endWord: return dist 

            for nextWord in graph[curWord]:
                q.put_nowait((nextWord, dist+1))


        return 0




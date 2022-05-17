# """
# This is Master's API interface.
# You should not implement it, or speculate about its implementation
# """
# class Master:
#     def guess(self, word: str) -> int:

from collections import defaultdict
# create weighted graph
# Create pool with every word 
# eliminate from pool as we visit and by checking distance against match

class Solution:
    def findSecretWord(self, wordlist: List[str], master: 'Master') -> None:
        def createGraph(wordlist: list):
            n = len(wordlist)
            graph = defaultdict(list)
            wordLen = len(wordlist[0])
            for i, curWord in enumerate(wordlist):
                for j in range(i+1, n):
                    nextWord = wordlist[j]
                    assert(len(curWord) == len(nextWord))
                    similarity = sum([1 if curWord[i] == nextWord[i] else 0 for i in range(wordLen)])
                    graph[curWord].append((nextWord, similarity))
                    graph[nextWord].append((curWord, similarity))


            return graph

        def getWordWithMostMatches(words, graph):
            leastZeroMatched, curWord = len(words)+1, ""
            for curWord in words:
                zeroMatched = 0
                for nextWord, similarity in graph[curWord]:
                    if similarity == 0 and nextWord in words:
                        zeroMatched += 1
                if zeroMatched < leastZeroMatched:
                    leastZeroMatched, curWord = zeroMatched, curWord

            return curWord

        def getGuessedWord(wordlist, graph, master):
            words, wordLen = set(wordlist), len(wordlist[0])

            while len(words) > 1:
                curWord = getWordWithMostMatches(words, graph)
                words.remove(curWord)
                match = master.guess(curWord)
                # print(f"cur:{curWord}")
                # print(f"match:{match}")
                # print(f"edges:{graph[curWord]}")
                if match == wordLen: return curWord
                for nextWord, similarity in graph[curWord]:
                    if similarity != match and nextWord in words:
                        words.remove(nextWord)

            assert(len(words) == 1)
            ans = words.pop()
            master.guess(ans)
            return str(ans)

        graph = createGraph(wordlist)
        return getGuessedWord(wordlist, graph, master)
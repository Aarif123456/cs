
map = {}
class CustomString(str):
    def __lt__(a:str, b:str) -> bool:
        for i in range(min(len(a), len(b))):
            if map[a[i]] != map[b[i]]: return map[a[i]] < map[b[i]]
        return len(a) < len(b)

class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        global map
        map = {}
        for i,c in enumerate(order):
            map[c] = i

        return words == sorted(words, key=CustomString)
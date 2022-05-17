class Trie:
    def __init__(self):
        self.word = None
        self.possible = [None for i in range(26)]

def buildTrie(words):
    root = Trie()
    for word in words:
        cur = root
        for c in word:
            i = ord(c)-ord('a')
            if cur.possible[i] is None: cur.possible[i] = Trie()
            cur = cur.possible[i]
        cur.word = word
    return root

def search(letters, pos, curTrie, found):
    x,y = pos
    c = letters[x][y]
    i = ord(c)-ord('a')
    if c == '-' or curTrie.possible[i] is None: return
    curTrie = curTrie.possible[i]
    if curTrie.word is not None:
        found.add(curTrie.word)
        curTrie.word = None

    letters[x][y] = "-"
    nxt = [(0,1),(1,0),(0,-1),(-1,0)]
    for addX, addY in nxt:
        curX, curY = x+addX, y+addY
        if curX >= 0 and curY >= 0 and curX < len(letters) and curY < len(letters[0]): search(letters, (curX, curY), curTrie, found)
    letters[x][y] = c

class Solution:

    def findWords(self, letters, words):
        root = buildTrie(words)
        found = set()

        for x in range(len(letters)):
            for y in range(len(letters[0])):
                search(letters, (x,y), root, found)

        out = []
        for word in words:
            if word in found: out.append(word)
        return out
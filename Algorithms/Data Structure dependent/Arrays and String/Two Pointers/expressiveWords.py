class Solution:
    def expressiveWords(self, s: str, words: List[str]) -> int:
        def runEncodeWord(s):
            cur, cnt = s[0], 0
            out = []
            for c in s:
                if c != cur:
                    out.append((cur, cnt))
                    cur = c
                    cnt = 0
                cnt += 1

            out.append((cur, cnt))
            return out

        def isWordStretchy(wordCount, word) -> bool:
            wordEncode = runEncodeWord(word)
            i, m, n = 0, len(wordCount), len(wordEncode)
            if  m != n: 
                return False
            for i in range(n):
                c1, i1, c2, i2 = *wordCount[i], *wordEncode[i] 
                # not matching character or not stretched
                if c1 != c2 or i1 < i2:
                    return False
                # if they aren't equal their needs to be a stretch 
                if i1 != i2 and i1 < 3:
                    return False
            return True 

        wordCount = runEncodeWord(s)
        cnt = 0
        for word in words:
            if isWordStretchy(wordCount, word):
                cnt += 1


        return cnt




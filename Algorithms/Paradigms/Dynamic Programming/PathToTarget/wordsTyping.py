class Solution:
    def wordsTyping(self, sentence: List[str], rows: int, cols: int) -> int:
        s = " ".join(sentence) + " "
        dp = [0]
        n, count = len(s), 0
        # if we have a space go to next line 
        # if we are in middle of a word we can't split word so we go to 
        # the start of the word
        for i in range(1, n):
            c=s[i]
            dp.append(1 if c == " " else dp[i-1]-1)

        for i in range(rows):
            count += cols
            count += dp[count%n]

        return count//n


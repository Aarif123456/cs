class Solution:
    def rankTeams(self, votes: List[str]) -> str:
        # represents candidates in the poll
        out = [ord(c)-ord('A') for c in votes[0]]
        out.sort()
        n = len(votes[0])
        # sort starting from least important vote to most important vote
        for i in range(n-1,-1,-1):
            count = [0]*26
            for vote in votes:
                count[ord(vote[i])-ord('A')] += 1
            out.sort(key = lambda x : count[x], reverse=True)

        return "".join([chr(ord('A')+i) for i in out])




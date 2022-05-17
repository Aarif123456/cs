class Solution:
    def findMinArrowShots(self, A: List[List[int]], k=1) -> int:
        # Sort by end time
        A.sort(key=lambda x: x[1])
        n, need, ans = len(A), k, []
        for i in range(n):
            ans += [A[i][1] - z for z in range(need)[::-1]]
            if i + 1 < n:
                need = k - sum(x >= A[i + 1][0] for x in ans)
        return len(ans)
class Solution:
    def checkRecord(self, n: int) -> int:
        mod = 10**9 + 7
        P = [1, 3, None]
        L = [1, 3, None]
        A = [1, 2, 4]

        for i in range(2, n):
            # Essentially cur, last value, and the value before last
            x_n, x_pn, x_ppn, x_pppn = i%3, (i+2)%3, (i+1)%3, i%3
            # We can add P to any string
            P[x_n] = (P[x_pn] + L[x_pn] + A[x_pn]) % mod
            # We can add L to any string - if it has at most 1 L at the end
            L[x_n] = (P[x_pn] + A[x_pn] + P[x_ppn] + A[x_ppn]) % mod
            # Add A if we have no other A in the string
            if i > 2: A[x_n] = (A[x_pn] + A[x_ppn] + A[x_pppn]) % mod


        return (P[(n-1)%3] + L[(n-1)%3] + A[(n-1)%3]) % mod
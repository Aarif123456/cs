from collections import defaultdict
# from pprint import pprint
class Solution:
    def mostSimilar(self, n: int, roads: list, names: list, targetPath: list) -> list:
        def createGraph(roads):
            graph = defaultdict(set)
            for s,e in roads:
                graph[s].add(e)
                graph[e].add(s)

            return graph

        def getPath(graph, names, targetPath):
            m, n = len(targetPath), len(names)
            INVALID = m+1
            # represents min edit distance if we end at city [j] at point [i] of our path
            dp = [[INVALID for j in range(n)] for i in range(m)]
            prev = [[-1 for j in range(n)] for i in range(m)]

            for i, target in enumerate(targetPath):
                for j, ending in enumerate(names):
                # we look at all the edges that can get us to the current node if this isn't the first step
                    best = 0

                    if i>0:
                        best = INVALID
                        for k in graph[j]:
                            if dp[i-1][k] < best:
                                best = dp[i-1][k]
                                prev[i][j] = k

                    dp[i][j] = best + (ending != target)

            # pprint(dp)
            # pprint(prev)

            bestPath = min(dp[-1])
            cur = dp[-1].index(bestPath)
            path = [cur]
            for i in range(-1,-m,-1):
                cur = prev[i][cur]
                path.append(cur)

            return path[::-1]
        
        graph = createGraph(roads)
        return getPath(graph, names, targetPath)


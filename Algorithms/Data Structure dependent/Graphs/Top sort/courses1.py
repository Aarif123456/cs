from collections import defaultdict
class Solution:
    def solve(self, courses):
        n = len(courses)
        graph = defaultdict(list)
        degrees = [0] * n
        for node, edges in enumerate(courses):
            for edge in edges:
                graph[edge].append(node)
                degrees[node]+=1
        # print(graph)
        bfs = [i for i in range(n) if degrees[i] == 0]
        # print(bfs)
        for i in bfs:
            for j in graph[i]:
                degrees[j]-=1
                if degrees[j] == 0:
                    bfs.append(j)
        # print(degrees)
        return not sum(degrees)
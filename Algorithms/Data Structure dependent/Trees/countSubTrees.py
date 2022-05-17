import collections
class Node: 
  def __init__(self, idx: int, data: int): 
    self.id = idx 
    self.val = data 
    self.children = []

class Solution:
    NUM_LETTER = 26

    # O(V+E) - make graph 
    def createGraph(self, n: int, edges: list[list[int]]):
        graph = {}
        for i in range(n):
            graph[i] = set()
        for start, end in edges:
            graph[start].add(end)
            graph[end].add(start)
        return graph

    # turn graph into tree O(V+E)
    def createTree(self, graph: list[list[int]], labels: str):
        visited = set()
        root = Node(1, ord(labels[0]) - ord('a'))
        q = collections.deque([root])
        while len(q) > 0:
            cur = q.popleft()
            visited.add(cur.id)
            for childNum in graph[cur.id-1]: 
                if childNum+1 not in visited:
                    node = Node(childNum+1, ord(labels[childNum]) - ord('a'))
                    cur.children.append(node)
                    q.append(node)

        return root

    # O(nK) 
    def countOccurence(self, root: Node, counter: list[list[int]])->list:
        if root is None: return 0
        for child in root.children:
            childNum = self.countOccurence(child, counter)
            for i in range(self.NUM_LETTER):
                counter[root.id][i] += counter[childNum][i]
        counter[root.id][root.val] += 1
        return root.id

    def countSubTrees(self, n: int, edges: list[list[int]], labels: str) -> list[int]:
        counter = [[0] * self.NUM_LETTER for _ in range(n+1)]
        graph = self.createGraph(n, edges)
        root = self.createTree(graph, labels)
        self.countOccurence(root, counter)
        return [counter[i+1][ord(c) - ord('a')] for i,c in enumerate(labels)]

sol = Solution()
test = [[0,2],[0,3],[1,2]]
s="aeed"

print(sol.countSubTrees(4, test, s))
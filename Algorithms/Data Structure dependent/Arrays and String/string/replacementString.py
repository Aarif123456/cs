class Solution:
    def findReplaceString(self, s: str, indices: List[int], sources: List[str], targets: List[str]) -> str:
        # Let
        # m = size of index
        # n = size of our string
        # s = size of output string
        
        # 1. bucket sort index by when they occur O(m)
        # 2. find if replacement occur O(mn) 
        # 3. Build new string with our replacement O(s)

        m, n = len(s), len(indices)
        buckets = [None] * m
        for i in range(n):
            index, src, tar = indices[i], sources[i], targets[i]
            if s.find(src, index, index + len(src)) == index:
                buckets[index] = (src, tar)


        skip = 0
        out = []
        for i, c in enumerate(s):
            if skip > 0:
                skip -= 1
            elif buckets[i] is not None:
                src, tar = buckets[i]
                skip = len(src) - 1 
                out.append(tar)
            else:
                out.append(c)

        return "".join(out)


        
def findPairsSummingToK(a, m, k):
    possiblePairs = {}
    n = len(a)
    count = 0
    curVal = 0
    for i in range(n):
        x = a[i]
        if (k-x) in possiblePairs: 
            curVal += 1
        if x not in possiblePairs:
            possiblePairs[x] = 0
        possiblePairs[x] += 1
            
        if i >= m:
            y =  a[i-m]
            possiblePairs[y] -= 1
            if k-y in possiblePairs: 
                curVal -= 1
            if possiblePairs[y] == 0:
                del possiblePairs[y]
        if i >= m-1:
            print(a[i-m+1:i+1])
            print(f"i:{i}, curVal:{curVal}")
            if curVal > 0:
                count += 1
    
    
    return count 
        
        
        
        

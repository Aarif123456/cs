def countDecreasingSubarrays(arr):
    if len(arr)<2: return len(arr)
    curCount = 0
    totalCount = 0
    for i in range(len(arr)):
        if i>0 and arr[i]>=arr[i-1]:
            totalCount += (curCount*(curCount+1))//2
            curCount = 0
        curCount += 1
    totalCount += (curCount*(curCount+1))//2
        
    return totalCount

print(countDecreasingSubarrays([1]))
print(countDecreasingSubarrays([]))
print(countDecreasingSubarrays([1,2,3,4]))
print(countDecreasingSubarrays([4,3,2,1]))

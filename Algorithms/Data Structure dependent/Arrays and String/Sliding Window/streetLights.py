def streetLights(n, lights):
    intervals = [(max(interval[0]-interval[1],0), min(interval[0]+interval[1],n)) for interval in lights]
    # Sort by start time
    intervals = sorted(intervals, key=lambda x:x[0])
    curReach = 0
    potentialGrasp = intervals[0][1]
    light = 0
    for i in range(len(intervals)):
       
        if curReach == n: 
            break
        if intervals[i][0] <= curReach and i<len(intervals)-1:
            potentialGrasp = max(potentialGrasp, intervals[i][1])
        elif intervals[i][0] <= potentialGrasp:
            curReach = potentialGrasp
            potentialGrasp = max(potentialGrasp, intervals[i][1])
            light+=1
        else:
            break
    
    return light if potentialGrasp==n else -1

n = 10
lights = [[0,5],[1,4],[4,2],[8,3]]
print(streetLights(n, lights) )
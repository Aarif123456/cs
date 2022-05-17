package main

import (
    "fmt"
    "math/bits"
)

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func racecar(target int) int {
    uTarget := uint32(target)
    bitsSet := 32 - bits.LeadingZeros32(uTarget)
    dp := make([]int, 1 << (bitsSet+1))
    
    steps:= 1
    for n := 2; n <= len(dp); n<<=1{
        dp[n-1] = steps
        steps++
    }

    last, next := 1, 3
    for i := 2; i <= target; i++ {
        if dp[i] != 0{
            last = i
            next = ((i+1) << 1) -1 
            continue
        }
        /* Go to last revere twice to reset and calculate distance to reach
         * current 
         */
        fromLast := dp[last] + 2 + dp[i-last]

        for j := 2; j <= i; j<<=1 {
            for n := 2; n < j; n<<=1 {
                /* Try to accelerate - turn back try some steps then 
                 * reverse back */
                x := i-((j-1)-(n-1))
                curSteps := dp[j-1] + 1 + dp[n-1] + 1 + dp[x]
                fromLast = min(fromLast, curSteps)
            }
        }
        
        /* +1 cause we go to next and reverse */
        fromNext := dp[next] + 1 + dp[next-i]
        dp[i] = min(fromLast, fromNext)
    }


    return dp[target]
}
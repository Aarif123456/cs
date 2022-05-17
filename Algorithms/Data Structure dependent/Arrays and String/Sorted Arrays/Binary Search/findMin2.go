package main
import (
    "fmt"
)
func findMin(nums []int) int {
    l, r := 0, len(nums)-1
    for l<r {
        m := l+(r-l)/2
        if nums[m] == nums[r]{ /*If mid same as right side - bring down right side */
            r--
            /* If mid is smaller then answer must lie in the left side A[l..m]*/
        } else if nums[m] < nums[r] {
            r = m
        } else { 
            l = m + 1
        } 
    }

    return nums[r]
}
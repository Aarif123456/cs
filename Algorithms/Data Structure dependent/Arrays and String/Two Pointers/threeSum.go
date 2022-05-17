import
(
    "sort"
)
func threeSum(nums []int) [][]int {
    sort.Ints(nums)
    const target = 0
    out := make([][]int, 0)
    for i, x := range nums {
        if i > 0 && nums[i-1] == x{
            continue
        }
        curSums := twoSums(nums, i+1, target-x)
        for _, pair := range curSums {
            curPair := []int{x}
            out = append(out, append(curPair, pair...))
        }
    }

    return out
}

func twoSums(nums []int, start int, target int) [][]int{
    end := len(nums)-1
    l, r := start, end
    out := make([][]int, 0)
    for l<r {
        curSum := nums[l] + nums[r]
        if curSum < target || (l > start && nums[l] == nums[l-1]){
            l++
        } else if curSum > target || (r+1 < end && nums[r] == nums[r+1]) {
            r--
        } else {
            curPair := []int{nums[l], nums[r]}
            out = append(out, curPair)
            l++
            r--
        }
    }
    return out
}
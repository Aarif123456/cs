func extractLSB(x int) int {
    return x & ^(x - 1)
}

func singleNumber(nums []int) []int {
    bitsDiffer := 0
    for _, x := range nums {
        bitsDiffer ^= x
    }
    /* We just need to get one bit that differs so we use the LSB */
    bitsDiffer = extractLSB(bitsDiffer)
    out := []int{0, 0}
    for _, x := range nums {
        /* If the current has the target bit set we use it as part of our answer */
        if (bitsDiffer & x) != 0 {
            out[0] ^= x
        } else { /* Second group */
            out[1] ^= x
        }
    }

    return out 
}
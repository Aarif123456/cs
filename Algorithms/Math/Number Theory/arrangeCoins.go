func arrangeCoins(n int) int {
    if n == 1 {
        return 1
    }
    l, r := 0, n
    for l < r {
        m := l + (r-l)/2
        /* n = (x * (x+1))/2 */
        if m * (m+1) > 2 * n  {
            r = m
        } else {
            l = m + 1
        }
    }

    return r-1
}
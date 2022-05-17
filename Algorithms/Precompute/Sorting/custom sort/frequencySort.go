func frequencySort(s string) string {
    m := make(map[byte]int)
    b := []byte(s)
    for _, c := range b {
        if _, ok := m[c]; !ok {
            m[c] = 0
        }
        m[c] += 1
    }
    /* SliceStale keeps original order*/
    sort.SliceStable(b, func(i, j int) bool{
        c1 := b[i]
        c2 := b[j]
        return m[c1] > m[c2] || (m[c1] == m[c2] && b[i] < b[j])
    })

    return string(b)
} 
import (
    "strings"
)

func longestDupSubstring(s string) string {
    l, r := 1, len(s)
    ans := ""
    for l <= r {
        m := l + (r-l)/2
        substrs := map[string]bool{}
        cs := s[:m]        
        substrs[cs] = true

        for i := m; i < len(s); i++ {
            cs = cs[1:] + string(s[i])
            if substrs[cs] {
                ans = cs
                break
            }
            substrs[cs] = true
        }

        if len(ans) >= l{
            l = m+1
        } else {
            r = m-1
        }
    }
    
    return ans

}
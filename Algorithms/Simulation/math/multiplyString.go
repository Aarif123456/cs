import (
    "strconv"
    "strings"
)

const zeroDig rune = '0'

/* Multiply digit to string */
func multiplyDigitWithString(num string, digit int) string{
    if digit > 9 || digit < 0 {
        panic("Digit must be between 0-9")
    }
    if digit == 0 {
        return "0"
    }

    carry, n := 0, len(num)
    outArr := make([]string, n+1)

    for i := n-1; i >= 0; i-- {
        d := int(rune(num[i]) - zeroDig)
        /* Handle multiplication operation */
        d *= digit
        d += carry
        carry = d/10 /* Get next carry*/
        /* Add current digit*/
        outArr[i+1] = strconv.Itoa(d % 10)
    }
    
    if carry == 0 {
        outArr = outArr[1:]
    } else {
        outArr[0] = strconv.Itoa(carry)
    }

    return strings.Join(outArr, "")
}

func addString(num1 string, num2 string) string {
    /* num1 should always be the bigger string */
    if len(num1) < len(num2){
        return addString(num2, num1)
    }
    /* Don't forget to add carry */
    carry := 0
    m, n := len(num1), len(num2)
    outArr := make([]string, m+1)
    for i := 1; i <= n; i++ {
        x1, x2 := int(rune(num1[m-i]) - zeroDig), int(rune(num2[n-i]) - zeroDig)
        x1 += x2 
        x1 += carry 
        carry = x1/10
        outArr[m+1-i] = strconv.Itoa(x1 % 10)
    }
    /* Process rest of first string */
    for i := n+1; i <= m; i++ {
        x1 := int(rune(num1[m-i]) - zeroDig)
        x1 += carry 
        carry = x1/10
        outArr[m+1-i] = strconv.Itoa(x1 % 10)
    }

    if carry == 0 {
        outArr = outArr[1:]
    } else {
        outArr[0] = strconv.Itoa(carry)
    }
    
    return strings.Join(outArr, "")
}

func multiply(num1 string, num2 string) string {
    /* num1 should always be the bigger string */
    if len(num1) < len(num2){
        return multiply(num2, num1)
    }

    out := ""
    for _, sd := range num2 {
        d := int(rune(sd) - zeroDig)
        cur := multiplyDigitWithString(num1, d)
        /* multiply answer by 10 and add them together */
        /* Note: this only works because we have no leading zero */
        out += "0"
        out = addString(out, cur)

    }

    return out
}
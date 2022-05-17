# flag="test"

def enc(flag:str)->str:
    a = []
    for i in range(0, len(flag), 2):
        a.append(chr((ord(flag[i]) << 8) + ord(flag[i + 1])))

    return ''.join(a)

def decChars(c: chr)-> str:
    mask = 0b11111111
    x = ord(c)

    secondLetter = x & mask
    firstLetter = (x - secondLetter)>>8
    return f"{chr(firstLetter)}{chr(secondLetter)}"

def dec(cp: str):
    return ''.join([decChars(c) for c in cp])

# cp = enc(flag)
print(dec("灩捯䍔䙻ㄶ形楴獟楮獴㌴摟潦弸弲㘶㠴挲ぽ"))

class Solution:
    def restoreIpAddresses(self, ip: str) -> List[str]:
        out = []
        matcher = r'(((1\d\d)|(2([0-4]\d|(5[0-5]))|[1-9]?\d))\.){3}((1\d\d)|(2([0-4]\d|(5[0-5]))|[1-9]?\d))'
        for i in range(1, 4):
            for j in range(i,i+4):
                if j>= len(ip): continue
                for k in range(j, j+4):
                    if k>= len(ip): continue
                    curIp = f"{ip[:i]}.{ip[i:j]}.{ip[j:k]}.{ip[k:]}"
                    if re.fullmatch(matcher, curIp) is not None: 
                        out.append(curIp)
                        
        return out
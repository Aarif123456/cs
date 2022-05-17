import base64

def base64_encode(s: str, encoding="utf-8")->bytes:
    return base64.b64encode(s.encode(encoding))

def base64_decode(b: bytes, encoding="utf-8")->str:
    return base64.b64decode(b).decode(encoding)

def bin2hex(b: bytes)->str:
    return b.hex()

def hex2bin(s: str)->bytes:
    return bytes.fromhex(s)

def rev(a):
    return a[::-1]

def encode(plaintext) -> str:
    return bin2hex(rev(base64_encode(plaintext)))

def decode(cipertext):
    return base64_decode(rev(hex2bin(cipertext)))

cp = encode("val")
print(cp)
pt = decode(cp)
print(pt)
print(decode("3d3d516343746d4d6d6c315669563362"))
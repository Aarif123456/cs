import json
import base64

def normalize_key(s: str):
    i, j, n, = 1, 0, len(s)
    dp = [0] * (n+1)

    while i < n:
        if s[i] == s[j]:
            i += 1
            j += 1
            dp[i] = j
        elif j == 0: i += 1
        else: j = dp[j]

    return s[:n-dp[n]]


def str_to_bytes(s: str, encoding="ascii")->str:
    return s.encode(encoding)

def bytes_to_str(b: bytes, encoding="ascii")->bytes:
    return b.decode(encoding)

def find_key(pt: str, cp: str)->bytes:
    ab = str_to_bytes(pt)
    bb = str_to_bytes(cp)
    assert(len(ab) == len(bb))

    return bytes(a ^ b for a, b in zip(ab, bb))

def xor_encrypt(text: str, key: bytes)->str:
    out = bytearray()

    # Iterate through each character
    for i, x in enumerate(str_to_bytes(text)):
        out.append(x ^ key[i % len(key)])
    
    return bytes_to_str(out)

def base64_encode(s: str)->bytes:
    return base64.b64encode(str_to_bytes(s))

def base64_decode(b: bytes)->str:
    return bytes_to_str(base64.b64decode(b))


def json_encode(d: dict)->str:
    return json.dumps(d, separators=(',', ':'))

def json_decode(s: str)->dict:
    return json.loads(s)

def encode(d: dict, key: bytes)->bytes:
    return base64_encode(xor_encrypt(json_encode(d), key))

def decode(b: bytes, key: bytes)->dict:
    return json_decode(xor_encrypt(base64_decode(b), key))

data = {
    "showpassword": "no", # will turn to yes later
    "bgcolor": "#ffffff",
}

originalCp = str_to_bytes("ClVLIh4ASCsCBE8lAxMacFMZV2hdVVotEhhUJQNVAmhSEV4sFxFeaAw=")
key = find_key(json_encode(data), base64_decode(originalCp))
key = normalize_key(key)

cp = encode(data, key)
assert(originalCp == cp)
pt = decode(cp, key)

desired_data = {
    "showpassword": "yes", 
    "bgcolor": "#ffffff",
}
print(encode(desired_data, key))

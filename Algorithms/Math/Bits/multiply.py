import unittest

def getBit(val: int, i: int):
    return val & (1 << i)

def setBit(val: int, i: int):
    return val | (1 << i)

def add(a: int, b: int):
    # return a+b
    mask = 0xffffffff
    carry, isBitSet = False, False
    ans = 0
    for i in range(32):
        x, y = getBit(a, i), getBit(b, i)
        if carry:
            carry = x | y
            isBitSet = not (x ^ y)
        else:
            carry = x & y
            isBitSet = x ^ y
        if isBitSet: ans = setBit(ans, i)

    return ans 

def multiply(a: int, b: int):
    ans = 0
    pos = (a < 0) == (b < 0)
    a,b = abs(a), abs(b)
    for i in range(32):
        if getBit(b, i): ans = add(ans, a << i)
    return ans if pos else -ans


class Testor(unittest.TestCase):
    def test_correctness(self):
        test_cases = \
            [
                [1,1],
                [1,10000000],
                [3,4],
                [1,-10000000],
                [7,1],
                [7,0],
                [-7,0],
                [-7,-8],
                [-1000,-100000],
                [-1000,100000],
            ]

        for a,b in test_cases:
            with self.subTest(a=a, b=b):
                self.assertEqual(add(a, b), a+b)
                self.assertEqual(multiply(a, b), a*b)


if __name__ == '__main__':
    unittest.main()
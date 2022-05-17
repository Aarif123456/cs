import math
def count_max_heads(nums):
    stack = [] # Mono decreasing stack
    ans = list(range(len(nums) - 1, -1, -1))

    for i, n in enumerate(nums):
        while stack and n >= stack[-1][1]:
            prev_idx, _ = stack.pop()
            ans[prev_idx] = i - prev_idx - 1
        stack.append((i, n))
    return ans


def count_subarrays(arr):
    max_heads = count_max_heads(arr)
    max_tails = count_max_heads(arr[::-1])[::-1]
    max_single_items = [1] * len(arr)

    return [sum(n) for n in zip(max_heads, max_tails, max_single_items)]


def printInteger(n):
    print('[', n, ']', sep='', end='')

def printIntegerList(array):
    size = len(array)
    print('[', end='')
    for i in range(size):
        if i != 0:
            print(', ', end='')
        print(array[i], end='')
    print(']', end='')

test_case_number = 1

def check(expected, output):
    global test_case_number
    expected_size = len(expected)
    output_size = len(output)
    result = True
    if expected_size != output_size:
        result = False
    for i in range(min(expected_size, output_size)):
        result &= (output[i] == expected[i])
    rightTick = '\u2713'
    wrongTick = '\u2717'
    if result:
        print(rightTick, 'Test #', test_case_number, sep='')
    else:
        print(wrongTick, 'Test #', test_case_number, ': Expected ', sep='', end='')
        printIntegerList(expected)
        print(' Your output: ', end='')
        printIntegerList(output)
        print()
    test_case_number += 1

if __name__ == "__main__":
    test_1 = [3, 4, 1, 6, 2]
    expected_1 = [1, 3, 1, 5, 1]
    output_1 = count_subarrays(test_1)
    check(expected_1, output_1)
    
    test_2 = [2, 4, 7, 1, 5, 3]
    expected_2 = [1, 2, 6, 1, 3, 1]
    output_2 = count_subarrays(test_2)
    check(expected_2, output_2)

    test_3 = [1, 2, 3, 4, 5, 6, 7]
    expected_3 = [1, 2, 3, 4, 5, 6, 7]
    output_3 = count_subarrays(test_3)
    check(expected_3, output_3)

    test_4 = [7, 6, 5, 4, 3, 2, 1]
    expected_4 = [7, 6, 5, 4, 3, 2, 1]
    output_4 = count_subarrays(test_4)
    check(expected_4, output_4)

    test_5 = [7, 6, 5, 4, 3, 2, 1, 2, 3, 4]
    expected_5 = [10, 9, 8, 6, 4, 2, 1, 2, 4, 6]
    output_5 = count_subarrays(test_5)
    check(expected_5, output_5)

    test_6 = [3, 6, 4, 1, 5, 2]
    expected_6 = [1, 6, 2, 1, 4, 1]
    output_6 = count_subarrays(test_6)
    check(expected_6, output_6)
    
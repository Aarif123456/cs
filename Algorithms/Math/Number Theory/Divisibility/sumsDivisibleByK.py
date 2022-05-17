
import math
import os
import random
import re
import sys

#
# Complete the 'divisibleSumPairs' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER K
#  3. INTEGER_ARRAY a

# Solve method: basic number theory, precompute info
# Insights
# 1. Each number will belong to some equivalent modulus class. So, k is 3 you will 3 mod classes. One for numbers with a remainder of 1, one for a remainder of 2 and lastly a remainder of 0.
# 2. Numbers divisible by the number can always form perfect pairs with each other. In other words, adding two numbers in the class of mod 0 will always keep the resulting number in the class mod 0.
# 3. For every other class the mod class will have an opposite pair, k-i where i is the current mod class and 0 < i < k
# 4. For even number we will have another mod class that creates a pair with itself. So, use the same logic as the mod class of zero
# 5. We can quickly use multiplication to calculate the total number of pairs if we have the number of item in the paired modulus classes. 
# 6. For mod classes that pair with themselves, we just use n*(n-1)/2. https://math.stackexchange.com/questions/2214839/exactly-how-does-the-equation-nn-1-2-determine-the-number-of-pairs-of-a-given

def divisibleSumPairs(n, K, A):
    if n<=1: return 0
    # Create a frequency array to count
    # occurrences of all remainders when
    # divided by K
    freq = [0] * K
     
    # Count occurrences of all remainders
    for i in range(n):
        freq[A[i] % K]+= 1
         
    # If both pairs are divisible by 'K'
    sum = freq[0] * (freq[0] - 1) / 2;
     
    # count for all i and (k-i)
    # freq pairs
    i = 1
    while i <= K//2 and i*2 != K:
        sum += freq[i] * freq[K-i]
        i+= 1
    
    # If K is even
    if K % 2 == 0 :
        sum += (freq[K//2] * (freq[K//2]-1))//2
     
    return int(sum)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    ar = list(map(int, input().rstrip().split()))

    result = divisibleSumPairs(n, k, ar)

    fptr.write(str(result) + '\n')

    fptr.close()

    
    

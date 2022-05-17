# Monotonic stacks

Monotonic stacks are stacks that maintain an monotonically increasing or decreasing order. 

## When
They help us in problems when we meet 3 criteria

1. We have a range query type problem. For example, in find sum of min element in every contiguous subarray. We need to find the min over a given span of i-j
2. The min or max of the range query helps us get the answer
3. When an element is popped from the stack it is never used again.

The third point is often the hardest to ensure.

## References

- https://labuladong.gitbook.io/algo-en/ii.-data-structure/monotonicstack
- https://medium.com/techtofreedom/algorithms-for-interview-2-monotonic-stack-462251689da8

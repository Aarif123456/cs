Branch and Bound
1. choice
2. constraint 
3. goal

Backtracking is DFS
Branch and Bound is BFS

Branch and bound only works for minimization problem

1. Pick a starting point.
2. while(not goal reached)
3.    For each path from the starting point.
4.        check if selected path satisfies constraint, if yes select it
5.        and make recursive call to rest of the problem
6.        undo the current move.
7.    End For
8. If none of the move works out, return false, NO SOLUTON.

Note: sorting can help handle tricky conditions such as duplicates


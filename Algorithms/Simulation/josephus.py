def josephus(n, m):
    p, i, seq = list(range(1,n+1)), 0, []
    while p:
        i = (i+m-1) % len(p)
        seq.append(p.pop(i)) # pop takes O(n)
    return 'Prisoner killing order: %s.\nSurvivor: %i' % (', '.join(str(i) for i in seq[:-1]), seq[-1])

print(josephus(8, 2))
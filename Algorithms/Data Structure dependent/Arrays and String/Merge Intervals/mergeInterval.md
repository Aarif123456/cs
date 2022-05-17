# Merge interval

## Key
Understand the following cases

1. Non-overlapping - a ends before b starts and a starts before b
    - |---------|
    -             |---------|
2. Overlapping - b starts before a has ended and a starts before b
    - |---------|
    -      |---------|
3. a engulfs b - b ends before a ends, and b starts after a has started
    - |-----------------|
    -      |---------|
Opposite 
4. Non-overlapping - b ends before a starts and b starts before a
    -             |---------|
    - |---------|
5. Overlapping - a starts before b has ended and b starts before a
    -      |---------|
    - |---------|
6. b engulfs a - a ends before b ends, and a starts after b has started
    -      |---------|
    -   |---------------|

Notice, if sorted by start - we only have 3 cases


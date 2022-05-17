func min(a int, b int) int{
    if a <= b {
        return a
    }
    return b
}

func max(a int, b int) int{
    if a >= b {
        return a
    }
    return b
}

const MaxInt = int(^uint(0) >> 1)

func orangesRotting(grid [][]int) int {
    const(
        empty = iota
        fresh
        rotten
    )
    nextDir := [][]int{{0,1},{0,-1},{1,0},{-1,0}}
    m, n := len(grid), len(grid[0])
    minDist := make([][]int, m)
    for i := range(minDist){
        minDist[i] = make([]int, n)
    }

    var spreadRot func(x, y, steps int) 
    spreadRot = func(x, y, steps int) {
        if x < 0 || y < 0 || x >= m || y >= n || minDist[x][y] <= steps {
            return 
        }
        minDist[x][y] = steps
        for _, next := range nextDir {
            spreadRot(x+next[0], y+next[1], steps+1)
        }
    }

    for x, row := range grid {
        for y, cell := range row {
            if cell == empty {
                continue
            }
            minDist[x][y] = MaxInt
        }
    }

    for x, row := range grid {
        for y, cell := range row {
            if cell == rotten {
                spreadRot(x, y, 0)
            }
        }
    }

    best := 0
    for _, row := range minDist {
        for _, cell := range row {
            best = max(best, cell)
        }
    }

    if best == MaxInt{
        return -1
    }
    return best
}
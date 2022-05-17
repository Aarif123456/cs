import(
    "math/big"
)

const (
    obstacle = iota -1
    empty 
    start
    end
)

/* Node in our graph will track our current coordinates and nodes we visited*/
type Node struct{
    Visited []big.Int
    NodesLeft int
    X int
    Y int
}

/* Count how many cells we can go to - which are free and destination */
func getFreeCount(grid [][]int) int {
    count := 0 
    for _, row := range grid {
        for _, cell := range row {
            if cell == empty  || cell == end {
                count++
            }
        }
    }

    return count
}

/* Get back coordinate of needle */
func findElement(grid [][]int, needle int) (int, int) {
    for x, row := range grid {
        for y, cell := range row {
            if cell == needle {
                return x, y
            }
        }
    }

    panic("cannot find needle")
}

/* Make deep copy of visited */
func copyVisited(visited []big.Int) []big.Int {
    cpy := make([]big.Int, len(visited))
    for i, curVis := range visited {
        cpy[i].Set(&curVis)
    }

    return cpy
}

func createInitialVisited(grid [][]int) []big.Int{
    visited := make([]big.Int, len(grid))
    for x, row := range grid {
        for y, cell := range row {
            if cell == obstacle || cell == start {
                visited[x].SetBit(&visited[x], y, 1)
            }
        }
    }

    return visited
}

func uniquePathsIII(grid [][]int) int {
    m, n := len(grid), len(grid[0])
    /* Mark all obstacle and start node as visited*/
    visited := createInitialVisited(grid)
    /* Count all the empty node and destination node*/
    freeCount := getFreeCount(grid)
    /* find starting and ending coordinates */
    sx, sy := findElement(grid, start)
    ex, ey := findElement(grid, end)
    /* Make stack with starting node */
    stack := make([]Node, 0)
    stack = append(stack, Node{visited, freeCount, sx, sy})
    /* track number of valid paths */
    validPath := 0
    for len(stack) > 0 {
        cur := stack[len(stack)-1]
        stack = stack[:len(stack)-1]
        if cur.X == ex && cur.Y == ey && cur.NodesLeft == 0 {
            validPath++
        }
        for _, next := range [][]int{{0,1},{0,-1},{1,0},{-1,0}} {
            dx, dy := next[0], next[1]
            nx, ny := cur.X + dx, cur.Y + dy
            if nx >= 0 && ny >= 0 && nx < m && ny < n && cur.Visited[nx].Bit(ny) == 0{
                visCpy := copyVisited(cur.Visited)
                visCpy[nx].SetBit(&visCpy[nx], ny, 1)
                newNode := Node{visCpy, cur.NodesLeft-1, nx, ny}
                stack = append(stack, newNode)
            }
        } 
    }

    return validPath
}
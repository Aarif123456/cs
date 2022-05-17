
const X, O, Z byte = 'X', 'O', 'Z'
var next [4][2]int = [4][2]int{{1,0},{-1,0},{0,1},{0,-1}}

func fill(board [][]byte, x int, y int){
    m, n := len(board), len(board[0])
    if x < 0 || y < 0 || x>=m || y>=n || board[x][y] != O {
        return
    }
    board[x][y] = Z
    for _, d := range next {
        dx, dy := d[0], d[1]
        fill(board, x+dx, y+dy)
    }
}

func fillBoardAtEdges(board [][]byte){
    m, n := len(board), len(board[0])
    /* Fill boards at edges */
    for x := 0; x < m; x++ {
        fill(board, x, 0)
        fill(board, x, n-1)
    }

    for y := 0; y < n; y++ {
        fill(board, 0, y)
        fill(board, m-1, y)
    }
}
func solve(board [][]byte){
    fillBoardAtEdges(board)
    for x, row := range board {
        for y, cell := range row {
            if cell == O {
                board[x][y] = X
            }
        }
    }
    for x, row := range board {
        for y, cell := range row {
            if cell == Z {
                board[x][y] = O
            }
        }
    }
}
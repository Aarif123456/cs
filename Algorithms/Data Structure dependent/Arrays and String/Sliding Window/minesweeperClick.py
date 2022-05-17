def createMatrix(field):
    return [[-1 for _x in row] for row in field]
    
visited = {}
m = []
def minesweeperClick(field, x, y):
    global m
    if len(visited) == 0: m = createMatrix(field)
    if (x,y) in visited: return m
    visited[(x,y)] = True
    
    dirs =  [[-1,0],[1,0],[0,-1],[0,1],[1,1],[1,-1],[-1,1],[-1,-1]]
    count = 0
    
    for d in dirs:
        curX = x+d[0]
        curY = y+d[1]
        if curX>=0 and curY>=0 and curX<len(field) and curY<len(field[0]) and field[curX][curY]:
            count += 1
    
    if count == 0:
        for d in dirs:
            curX = x+d[0]
            curY = y+d[1]
            if curX>=0 and curY>=0 and curX<len(field) and curY<len(field[0]):
                m = minesweeperClick(field, curX, curY)
    m[x][y]=count    
    return m
    

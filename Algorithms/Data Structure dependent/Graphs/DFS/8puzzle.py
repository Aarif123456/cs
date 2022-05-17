import copy
from queue import Queue
class Solution:
    ans = [[0, 1, 2],[3, 4, 5],[6, 7, 8]]
    maskNum = [[1,2,4],[8,16,32],[64,128,256]]
    DONE = 511 # all bits are set
    def getMask(self, board):
        mask = 0
        for i in range(3):
            for j in range(3):
                if board[i][j] == self.ans[i][j]: 
                    mask |= self.maskNum[i][j]
        return mask

    def findZero(self, board):
        for i in range(3):
            for j in range(3):
                if board[i][j] == 0: return (i,j)

    def solve(self, board):
        visited = set()
        q = Queue()
        pos =  self.findZero(board)
        q.put_nowait((board, 0, pos, self.getMask(board)))
        ans = 1000
        dirX = [-1,1,0,0]
        dirY = [0,0,-1,1]
        while not q.empty():
            board, steps, pos, mask = q.get_nowait()
            zeroX,zeroY = pos
            if steps > ans: continue
            s = ''.join(str(n) for row in board for n in row)
            if s in visited: continue
            # print(steps)
            print(s)
            print(mask)
            visited.add(s)
            if mask == self.DONE:
                ans = steps
            for i in range(4):
                nextX, nextY = zeroX+dirX[i], zeroY+dirY[i]

                if nextX >=0 and nextX < 3 and nextY >= 0 and nextY < 3:
                    zero = (nextX, nextY)
                    nextBoard = copy.deepcopy(board)
                    newMask = mask
                    # if either of our two positions were in correct position remove them because they are about to be set 
                    newMask &= ~self.maskNum[zeroX][zeroY]
                    newMask &= ~self.maskNum[nextX][nextY]

                    nextBoard[nextX][nextY],nextBoard[zeroX][zeroY] = nextBoard[zeroX][zeroY], nextBoard[nextX][nextY]

                    if nextBoard[nextX][nextY] == 0: newMask |= 1
                    if nextBoard[zeroX][zeroY] == zeroX*3 + zeroY:
                        newMask |= self.maskNum[zeroX][zeroY]
                    q.put_nowait((nextBoard, steps+1, zero, newMask))
            
        return ans if ans != 1000 else -1
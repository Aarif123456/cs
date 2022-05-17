# """
# This is the robot's control interface.
# You should not implement it, or speculate about its implementation
# """
#class Robot:
#    def move(self):
#    def turnRight(self):
#    def clean(self):

class Solution:
    def cleanRoom(self, robot):
        dirs = [(0,1), (1,0), (0, -1), (-1,0)]
        visited = set()
        def search(robot, visited, x, y, curDir):
            nonlocal dirs
            if (x,y) not in visited:
                robot.clean()
                visited.add((x,y))
                # print(f"{x},{y}")

                for i in range(4):
                    nextDir = (i+curDir) % 4
                    nextDirX, nextDirY = dirs[nextDir]
                    if robot.move():
                        search(robot, visited, x+nextDirX, y+nextDirY, nextDir)
                    robot.turnRight()

            # face the way we came in
            robot.turnRight()
            robot.turnRight()
            robot.move() # go back to old cell
            # face the way we were facing when we came in
            robot.turnRight()
            robot.turnRight()

        search(robot, visited, 0, 0, 0)


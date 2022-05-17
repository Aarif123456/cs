typedef std::pair<int, int> pii;

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

typedef std::unordered_set<pii, pair_hash> u_pii_set;
class Solution {
public:
    const int dirX[4] = {0, 1, 0, -1};
    const int dirY[4] = {1, 0, -1, 0};

    void goBack(Robot& robot){
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight(); 
    }

    void moveRobot(Robot& robot,  u_pii_set& visited, const pii& pos, int curDir){
        auto nextPos = make_pair(pos.first+ dirX[curDir], pos.second + dirY[curDir]);
        cleanRoom(robot, visited, nextPos, curDir);

    }

    void cleanRoom(Robot& robot,  u_pii_set& visited, const pii& pos, int curDir = 0){
        if(visited.find(pos) == visited.end()){
            robot.clean();
            visited.insert(pos);
            
            /* Go straight */
            if(robot.move()) moveRobot(robot, visited, pos, curDir);

            /* Go right */
            robot.turnRight();
            if(robot.move()) moveRobot(robot, visited, pos, (curDir + 1) % 4);
            
            /* Go back*/
            robot.turnRight();
            if(robot.move()) moveRobot(robot, visited, pos, (curDir + 2) % 4);

            /* Go left */
            robot.turnRight();
            if(robot.move()) moveRobot(robot, visited, pos, (curDir + 3) % 4);

            /* Re straighten */
            robot.turnRight();
        }

        /* Go back and face same direction */
        goBack(robot);
    }

    void cleanRoom(Robot& robot){
        u_pii_set visited;
        cleanRoom(robot, visited, make_pair(0, 0));
    }
};
typedef std::pair<int,int> pii;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;

class Solution {
public:
    vi dirX = {-1,1,0,0};
    vi dirY = {0,0,-1,1};
    /* Mark island with marker and return size*/
    int getIslandSize(vvi& grid, int islandNum, pii cur){
        if(grid[cur.first][cur.second] <= 0) return 0;
        int n = grid.size(), m = grid[0].size(), islandSize = 0;
        std::stack<pii> stack;
        stack.push(cur);
        while(!stack.empty()){
            cur = stack.top(); stack.pop();
            if(grid[cur.first][cur.second] <= 0) continue;
            islandSize++;
            grid[cur.first][cur.second] = islandNum;
            for (int i = 0; i < 4; i++){
                int nxtX = cur.first+dirX[i];
                int nxtY = cur.second+dirY[i];
                if(nxtX>=0 && nxtY>=0 && nxtX<n && nxtY<m && grid[nxtX][nxtY] == 1){
                    stack.push(make_pair(nxtX, nxtY));
                }
            }
        }
        return islandSize;
    }
    int getCombinedIslandSize(vvi& grid, vi& islandSizes, pii cur){
        if(grid[cur.first][cur.second] != 0) return 0;
        unordered_set<int> islandNums;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < 4; i++){
            int nxtX = cur.first+dirX[i];
            int nxtY = cur.second+dirY[i];
            if(nxtX>=0 && nxtY>=0 && nxtX<n && nxtY<m && grid[nxtX][nxtY] < 0){
                islandNums.insert(-(grid[nxtX][nxtY]+1));
            }
        }
        /* The initial water become an island*/
        int combSize = 1;
        for(auto n: islandNums) combSize += islandSizes[n];
        return combSize;
    }

    int largestIsland(vector<vector<int>>& grid) {
        vi islandSizes;
        int n = grid.size(), m = grid[0].size();
        if (n==0) return 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int size = getIslandSize(grid, -(islandSizes.size()+1), make_pair(i,j));
                if(size) islandSizes.push_back(size);
            }
        }
        if(islandSizes.empty()) return 1;
        int best = islandSizes.back();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                best = max(best, getCombinedIslandSize(grid, islandSizes, make_pair(i,j)));
            }
        }
        return best;
    }
};
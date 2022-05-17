class Solution {
    class State{
        public int x,y;
        public State(int x, int y){
            this.x=x;
            this.y=y;
        }
        public List<State> getNext(char[][] grid){
            List<State> out = new ArrayList<>();
            int[] dx = new int[]{0,0,1,-1};
            int[] dy = new int[]{1,-1,0,0};
            for(int i=0; i<dx.length; i++){
                int newX = this.x+dx[i], newY=this.y+dy[i];
                if( newX<grid.length && 
                    newX>=0 && 
                    newY<grid[0].length && 
                    newY>=0 && 
                    grid[newX][newY] == '1') 
                {
                    out.add(new State(newX, newY));
                }
            }
            
            return out;
        }
    }

    private void fill(char[][] grid, int x, int y){
        ArrayDeque<State> next = new ArrayDeque();
        // Set<Integer> visited = new HashSet<>();
        next.push(new State(x, y));
        while(!next.isEmpty()){
            State cur = next.pop();
            x=cur.x;
            y=cur.y;
            int pos=grid.length*x+y;
            // if(visited.contains(pos)) continue;
            // visited.add(pos);
            grid[x][y] = '-';
            next.addAll(cur.getNext(grid));
        }
    }

    public int numIslands(char[][] grid) {
        int numIslands=0;
        for(int i=0; i<grid.length; i++){
            for (int j=0; j<grid[0].length; j++) {
                if(grid[i][j] == '1'){
                    fill(grid, i, j);
                    numIslands++;
                }
            }
        }

        return numIslands;
    }
}
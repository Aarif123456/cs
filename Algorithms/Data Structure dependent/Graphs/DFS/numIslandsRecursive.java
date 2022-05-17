class Solution {
    static int[] dx = new int[]{0,0,1,-1};
    static int[] dy = new int[]{1,-1,0,0};
    private void fill(char[][] grid, int x, int y){
        for(int i=0; i<4; i++){
            int newX = x+dx[i], newY=y+dy[i];
            if( newX<grid.length && 
                newX>=0 && 
                newY<grid[0].length && 
                newY>=0 && 
                grid[newX][newY] == '1') 
            {
                grid[newX][newY] = '-';
                fill(grid, newX, newY);
            }
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
// https://leetcode.com/problems/max-area-of-island/description/

void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int currrow, int currcol, int rows, int cols, int &numCells){
    vis[currrow][currcol] = 1;
    numCells++;

    // vis neigh 
    int delrow[] = {-1, +1, 0, 0};
    int delcol[] = {0, 0, -1, +1};

    for(int i = 0;i<4;i++){
        int nr = currrow + delrow[i];
        int nc = currcol + delcol[i];

        if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && vis[nr][nc] == -1 && grid[nr][nc] == 1){
            dfs(grid, vis, nr, nc, rows, cols, numCells);
        }
    }
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int>>vis(rows, vector<int>(cols, -1));

    int maxNumCells = 0;

    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            if(grid[i][j] == 1 && vis[i][j] == -1){
                int numCells = 0;
                dfs(grid, vis, i, j, rows, cols, numCells);
                maxNumCells = max(maxNumCells, numCells);
            }
        }
    }

    return maxNumCells;
}
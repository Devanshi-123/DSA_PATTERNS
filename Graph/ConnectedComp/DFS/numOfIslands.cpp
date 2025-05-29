// https://leetcode.com/problems/number-of-islands/

void dfs(vector<vector<char>> &grid,int currrow, int currcol,int rows,int cols,vector<vector<int>> &vis){
    vis[currrow][currcol] = 1;

    // neigh 
    int delrow[] = {-1, +1, 0, 0};
    int delcol[] = {0, 0,+1, -1};

    for(int i = 0; i<4; i++){
        int newrow = currrow + delrow[i];
        int newcol = currcol + delcol[i];

        if(newrow >= 0 && newrow < rows && newcol >= 0 && newcol < cols && grid[newrow][newcol] == '1' && vis[newrow][newcol] == -1){
            dfs(grid, newrow, newcol, rows, cols, vis);
        }
    }

}
int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    // 1 : land , 0 : water 

    vector<vector<int>>vis(m, vector<int>(n, -1));
    int count = 0;

    for(int i = 0; i<m;i++){
        for(int j = 0; j<n; j++){
            if(grid[i][j] == '1' && vis[i][j] == -1){
                dfs(grid, i, j, m, n, vis);
                count++;
            }
        }
    }

    return count;
}
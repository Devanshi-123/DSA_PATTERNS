// totalNumberOnes - boundary se connected ones 

// https://leetcode.com/problems/number-of-enclaves/submissions/1629191155/

void dfs(vector<vector<int>> &grid,vector<vector<int>> &vis,int rows,int cols,int currrow,int currcol,int &count){
    cout << "cr" << currrow << " " << "col" << currcol << endl;
    vis[currrow][currcol] = 1;
    count++;

    // explore neight 
    int delrow[] = {-1, +1, 0, 0};
    int delcol[] = {0, 0, -1, +1};

    for(int i = 0; i<4;i++){
        int newrow = currrow + delrow[i];
        int newcol = currcol + delcol[i];

        if(newrow >= 0 && newrow < rows && newcol >= 0 && newcol < cols && grid[newrow][newcol] == 1 && vis[newrow][newcol] == -1){
            dfs(grid, vis, rows, cols, newrow, newcol, count);
        }
    }
}
int numEnclaves(vector<vector<int>>& grid) {
    // m*n 
    // 0 : sea 
    // 1 : land 

    int totalOnes = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;

    vector<vector<int>>vis(rows, vector<int>(cols, -1));

    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            if(grid[i][j] == 1){
                totalOnes++;
            }
            if(grid[i][j] == 1 && vis[i][j] == -1 && (i == 0 || i == rows-1 || j == 0 || j == cols-1)){
                cout << "grid " << grid[i][j] << endl;
                dfs(grid, vis, rows, cols, i, j, count);
            }
        }
    }

    cout << "total" << totalOnes << endl;
    cout << "bundary" << count << endl;

    return totalOnes - count; 
}
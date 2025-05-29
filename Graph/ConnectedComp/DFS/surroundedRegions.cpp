// https://leetcode.com/problems/surrounded-regions/submissions/1629239613/


void dfs(vector<vector<char>> &board,int rows,int cols,int currrow,int currcol,vector<vector<int>> &vis){
    vis[currrow][currcol] = 1;

    // neigh 
    int delrow[] = {0, 0, -1, +1};
    int delcol[] = {-1, +1, 0, 0};

    for(int i = 0; i<4;i++){
        int newrow = currrow + delrow[i];
        int newcol = currcol + delcol[i];

        if(newrow >= 0 && newrow < rows && newcol >= 0 && newcol < cols && board[newrow][newcol] == 'O' && vis[newrow][newcol] == -1){
            dfs(board, rows, cols, newrow, newcol, vis);
        }
    }
}
void solve(vector<vector<char>>& board) {
    // instead of 0s connected with the border os we can make all others as x 

    int rows = board.size();
    int cols = board[0].size();

    vector<vector<int>>vis(rows, vector<int>(cols, -1));

    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            if(board[i][j] == 'O' && vis[i][j] == -1 && (i == 0 || i == rows-1 || j == 0 || j == cols-1)){
                dfs(board, rows,cols, i, j, vis);
            }
        }
    }

    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            if(vis[i][j] == -1){
                board[i][j] = 'X';
            }
        }
    }
}
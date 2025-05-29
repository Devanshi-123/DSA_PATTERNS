// https://leetcode.com/problems/rotting-oranges/description/

// Time : O(m*n*4)
// Space : O(m*n)
// where m is the number of rows and n is the number of columns

int bfs(vector<vector<int>>&grid,int rows,int cols,vector<vector<int>>& vis,queue<pair<int, pair<int,int>>> &q,int &numFresh){
    while(!q.empty()){
        int currTime = q.front().first;
        int currrow = q.front().second.first;
        int currcol = q.front().second.second;

        if(grid[currrow][currcol] == 1){
            numFresh--;
        }

        cout << "ct" << currTime << endl;
        cout << "cr" << currrow << endl;
        cout << "cc" << currcol << endl;

        q.pop();

        // explore neigh 

        if(numFresh == 0){
            return currTime;
        }

        int delrow[] = {0, 0, -1, +1};
        int delcol[] = {-1, +1, 0, 0};

        for(int i = 0; i<4;i++){
            int nr = currrow + delrow[i];
            int nc = currcol + delcol[i];

            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1 && vis[nr][nc] == -1){
                cout << "nr" << nr << "nc" << nc << endl;
                q.push({currTime+1, {nr, nc}});
                vis[nr][nc] = 1;
            }
        }
    }

    return -1;
}
int orangesRotting(vector<vector<int>>& grid) {
    // multisource bfs 
    int rows = grid.size();
    int cols = grid[0].size();

    // 0 : empty , 1 : fresh b, 2 : rotten 

    // source : rotten  
    int numFresh = 0;

    vector<vector<int>>vis(rows, vector<int>(cols , -1));

    queue<pair<int, pair<int,int>>>q;

    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            if(grid[i][j] == 2){
                q.push({0, {i, j}});
                vis[i][j] = 0 ;
            }else if(grid[i][j] == 1){
                numFresh++;
            }
        }
    }

    if(numFresh == 0){
        return 0;
    }

    cout << "nf" << numFresh << endl;

    return bfs(grid, rows, cols, vis, q, numFresh);
}
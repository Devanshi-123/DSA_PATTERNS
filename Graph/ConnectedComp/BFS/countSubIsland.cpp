// https://leetcode.com/problems/count-sub-islands/

// Time Complexity : O(N*M)
// Space Complexity : O(N*M) + O(N*M) for vis and queue

bool bfs(vector<vector<int>>& master, vector<vector<int>>& grid, queue<pair<int,int>> &q,vector<vector<int>> &vis, int rows, int cols){
    bool flag = true;
    while(!q.empty()){
        int currRow = q.front().first;
        int currCol = q.front().second;

        q.pop();

        // neighbours 
        int delrow[] = {-1,0, +1, 0};
        int delcol[] = {0, -1, 0, +1};

        for(int i = 0; i<4;i++){
            int newRow = currRow + delrow[i];
            int newCol = currCol + delcol[i];

            if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1 && vis[newRow][newCol] == -1 ){
                if(master[newRow][newCol] == 0){
                    flag = false;
                }
                vis[newRow][newCol] = 1;
                q.push({newRow, newCol});
            }
        }
    }
    return flag;
}
int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int rows = grid1.size();
    int cols = grid1[0].size();

    // 0 > water , 1 > land 
    // island : group of 1s connected 4 directionally 

    map<vector<pair<int,int>>, int>subgridMap;

    queue<pair<int,int>>q;

    int count = 0;
    vector<vector<int>>subgridvis(rows, vector<int>(cols, -1));
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols;j++){
            if(grid2[i][j] == 1 && grid1[i][j] == 1 && subgridvis[i][j] == -1){
                q.push({i,j});
                subgridvis[i][j] = 1;
                if(bfs(grid1, grid2, q, subgridvis, rows, cols) == true){
                    count++;
                }
            }
        }
    }

    return count;

}
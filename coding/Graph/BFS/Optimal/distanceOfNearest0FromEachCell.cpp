// https://leetcode.com/problems/01-matrix/

void bfs(queue<pair<int, pair<int,int>>>&q, vector<vector<int>> &vis, vector<vector<int>> &dist, vector<vector<int>> &mat, int rows, int cols){
    while(!q.empty()){
        int currCount = q.front().first;
        int currrow = q.front().second.first;
        int currcol = q.front().second.second;

        q.pop();

        // explore neigh 
        int delrow[] = {-1, +1, 0, 0};
        int delcol[] = {0, 0, -1, +1};

        for(int i = 0; i<4; i++){
            int nr = currrow + delrow[i];
            int nc = currcol + delcol[i];
            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && mat[nr][nc] == 1 && vis[nr][nc] == -1){
                vis[nr][nc] = 1;
                dist[nr][nc] = currCount+1;
                q.push({currCount+1, {nr, nc}});
            }
        }
    }
}
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    vector<vector<int>>dist(rows, vector<int>(cols, 0));
    vector<vector<int>>vis(rows, vector<int>(cols, -1));

    queue<pair<int, pair<int,int>>>q;

    // multisource bfs where all the 1s are our sources 

    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            if(mat[i][j] == 0){
                q.push({0, {i, j}});
                vis[i][j] = 1;
            }
        }
    }

    bfs(q, vis, dist, mat, rows, cols);

    return dist;
}
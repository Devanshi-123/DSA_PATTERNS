// https://leetcode.com/problems/shortest-path-in-binary-matrix/submissions/1631476747/

int bfs(queue<pair<int, pair<int,int>>> &q,vector<vector<int>>&  vis,vector<vector<int>>&  grid,int rows,int cols){
    while(!q.empty()){
        int cl = q.front().first;
        int cr = q.front().second.first;
        int cc = q.front().second.second;

        if(cr == rows-1 && cc == cols-1){
            return cl;
        }

        q.pop();

        // explore neigh 
        int delrow[] = {0, 0, -1, +1, -1, -1, +1, +1};
        int delcol[] = {-1, +1, 0, 0, -1, +1, -1, +1};

        for(int i = 0; i<8;i++){
            int nr = cr + delrow[i];
            int nc = cc + delcol[i];

            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && vis[nr][nc] == -1 && grid[nr][nc] == 0){
                vis[nr][nc] = 1;
                q.push({cl+1, {nr, nc}});
            }
        }
    }
    return -1;
}
public:
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int>>vis(rows, vector<int>(cols, -1));

    queue<pair<int, pair<int,int>>>q;

    if(grid[0][0] != 0 || grid[rows-1][cols-1] != 0){
        return -1;
    }
    

    q.push({1, {0,0}});
    vis[0][0] = 1;

    return bfs(q, vis, grid, rows, cols);
}
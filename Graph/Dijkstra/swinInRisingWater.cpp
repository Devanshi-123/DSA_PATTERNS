// https://leetcode.com/problems/swim-in-rising-water/description/

int dijkstra(priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> &pq, vector<vector<int>> &vis, int rows, int cols, int targetRow, int targetCol, vector<vector<int>>& grid){
    while(!pq.empty()){
        int currTime = pq.top().first;
        int currRow = pq.top().second.first;
        int currCol = pq.top().second.second;

        if(currRow == targetRow && currCol == targetCol){
            return currTime;
        }

        pq.pop();

        int delrow[] = {-1, +1, 0, 0};
        int delcol[] = {0, 0, -1, +1};

        for(int i = 0; i<4; i++){
            int newRow = delrow[i] + currRow;
            int newCol = delcol[i] + currCol;

            if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && vis[newRow][newCol] == -1){
                int maxTime = max(currTime, grid[newRow][newCol]);
                pq.push({maxTime, {newRow, newCol}});
                vis[newRow][newCol] = 1;
            }
        }
    }

    return -1;
}
int swimInWater(vector<vector<int>>& grid) {
    // weighted graph 
    // src 
    // target 
    // min cost to reach from src to target 

    // dijkstra 

    int rows = grid.size();
    int cols = grid[0].size();
    int srcRow = 0;
    int srcCol = 0;
    int targetRow = rows-1;
    int targetCol = cols-1;
    vector<vector<int>>vis(rows, vector<int>(cols, -1));
    
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>>minHp;

    minHp.push({grid[srcRow][srcCol],{srcRow, srcCol}});
    vis[srcRow][srcCol] = 1;

    return dijkstra(minHp, vis, rows, cols, targetRow, targetCol, grid);
}
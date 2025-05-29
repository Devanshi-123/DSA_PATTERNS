// https://leetcode.com/problems/pacific-atlantic-water-flow/submissions/1406610317/

class Solution {
    public:
        void bfs(queue<pair<int,int>>q,vector<vector<int>>& heights,vector<vector<int>>&ocean, int rows, int cols){
            while(!q.empty()){
                int currrow = q.front().first;
                int currcol = q.front().second;
                int curheight = heights[currrow][currcol];
    
                q.pop();
    
                int delrow[] = {-1, 0, 0, +1};
                int delcol[] = {0, -1, +1, 0};
    
                for(int i=0;i<4;i++){
                    int newrow = currrow + delrow[i];
                    int newcol = currcol + delcol[i];
    
                    if(newrow >= 0 && newrow < rows && newcol >= 0 && newcol < cols && ocean[newrow][newcol] == 0 && heights[newrow][newcol] >= heights[currrow][currcol]){
                        q.push({newrow, newcol});
                        ocean[newrow][newcol] = 1;
                    }
                }
    
            }
        }
        vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
            // pacific : top and left 
            // atlantic : bottom and right 
    
            int rows = heights.size();
            int cols = heights[0].size();
    
            // water can flow in 4 direction if the height of neighbour iss <= current height 
    
            // border cell than water can flow to the ocean 
    
            vector<vector<int>>grid;
            vector<vector<int>>pacific(rows, vector<int>(cols, 0));
            vector<vector<int>>atlantic(rows, vector<int>(cols, 0));
    
            queue<pair<int,int>>pacificOcean;
            queue<pair<int,int>>atlanticOcean;
    
            // all the top and left can recah pacific 
    
            // all the bottom and right can reach atlantic 
    
            // multisource bfs 
    
            for(int i=0;i<rows;i++){
                pacificOcean.push({i,0});
                atlanticOcean.push({i, cols-1});
                pacific[i][0] = 1;
                atlantic[i][cols-1] = 1;
            }
    
            for(int j=0;j<cols;j++){
                pacificOcean.push({0,j});
                atlanticOcean.push({rows-1, j});
                pacific[0][j] = 1;
                atlantic[rows-1][j] = 1;
            }
    
            bfs(pacificOcean, heights, pacific, rows, cols);
            bfs(atlanticOcean, heights, atlantic, rows, cols);
    
            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    if(pacific[i][j] == 1 && atlantic[i][j] == 1){
                        grid.push_back({i,j});
                    }
                }
            }
    
            return grid;
        }
    };
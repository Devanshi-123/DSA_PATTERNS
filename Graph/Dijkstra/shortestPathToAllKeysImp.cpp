// https://leetcode.com/problems/shortest-path-to-get-all-keys/

// Time : O(m*n*2^k log(m*n*2^k))
// Space : O(m*n*2^k)
// m*n : grid size
// 2^k : keys combinations (all the paths to traverse)
// k : number of keys
// dijkstra
// priority queue

class Solution {
    public:
    
        struct myStruct{
            int row;
            int col; 
            int numOfMoves;
            int keymask;
        };
            struct Compare {
        bool operator()(const myStruct &a, const myStruct &b) const {
            return a.numOfMoves > b.numOfMoves;
        }
    };
        int dijkstra(vector<string>& grid,int rows,int cols, priority_queue<myStruct, vector<myStruct>,Compare> &pq, vector<vector<vector<int>>> &vis, int allKeysMask){
            while(!pq.empty()){
                int numOfMoves = pq.top().numOfMoves;
                int currRow = pq.top().row;
                int currCol = pq.top().col;
                int keyMask = pq.top().keymask;
    
                pq.pop();
    
                if(isalnum(grid[currRow][currCol]) && islower(grid[currRow][currCol])){
                    // if foound a key set in the keymask 
                    keyMask |= 1 << (grid[currRow][currCol] - 'a');
                }
    
                // if we found all keys
                if(keyMask == allKeysMask){
                    return numOfMoves;
                }
    
                int delrow[] = {-1, +1, 0, 0};
                int delcol[] = {0, 0, +1, -1};
    
                for(int i = 0; i<4; i++){
                    int newRow = currRow + delrow[i];
                    int newCol = currCol + delcol[i];
    
                    if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && vis[newRow][newCol][keyMask] == -1 && grid[newRow][newCol] != '#'){
    
                        // if there is a lock check if its a set bit or not at that position i.e if there is a key for that lock or not if no key for that lock we cant go through that lock 
                        if (isupper(cell)) {
                            // It's a lock; check if we have the key
                            if ((keyMask & (1 << (cell - 'A'))) == 0) continue;
                        }
    
                        pq.push({
                            newRow, 
                            newCol, 
                            numOfMoves+1, 
                            keyMask
                        });
                        vis[newRow][newCol][keyMask] = 1;
                    }
                }
            }
    
            return -1;
        }
        int shortestPathAllKeys(vector<string>& grid) {
            int rows = grid.size();
            int cols = grid[0].size();
    
            // . : empty 
            // # : wall 
            // @ : starting point 
    
            // lowercase keys
            // uppercase : locks
    
            // 4 directions 
            // no outside or wall 
    
            // pq 
    
            // keys 
            // locks :
    
            // 5 , 1, 4
            // 5, 2, 3
            // 6, 2, 4 : key : b 
    
            // priority queue
            // dijkstra 
    
    
            // pq to store moves , row, col
            priority_queue<myStruct, vector<myStruct>, Compare>pq;
            // as maximum 6 keys are possible 
            vector<vector<vector<int>>>vis(rows,(vector<vector<int>>(cols, vector<int>(1 << 6, -1))));
    
            myStruct ms;
            int allKeysMask = 0;
    
            for(int i = 0; i<rows; i++){
                for(int j = 0; j<cols; j++){
                    // push the start point to the priority queue
                    if(grid[i][j] == '@'){
                        ms.row = i;
                        ms.col = j;
                        ms.numOfMoves = 0;
                        ms.keymask = 0;
                        pq.push(ms);
                        vis[i][j][0] = 1;
                    }
                    if(isalnum(grid[i][j])){
                        if(islower(grid[i][j])){
                            // we have a set bit at the position of keys
                            allKeysMask |= (1 << (grid[i][j] - 'a'));
                        }
                    }
                }
            }
    
            return dijkstra(grid,rows, cols, pq, vis, allKeysMask);
    
    
        }
    };
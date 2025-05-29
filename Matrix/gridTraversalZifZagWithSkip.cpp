// https://leetcode.com/problems/zigzag-grid-traversal-with-skip

// O(n*m) time and O(n*m) space

class Solution {
    public:
        vector<int> zigzagTraversal(vector<vector<int>>& grid) {
            vector<int>ans;
            int rows = grid.size();
            int cols = grid[0].size();
            int row = true;
            int col = true;
            for(int i = 0; i<rows; i++){
                if(row == true){
                    for(int j = 0;j <cols; j++){
                        if(col == true){
                            ans.push_back(grid[i][j]);
                            col = false;
                        }else {
                            col = true;
                        }
                    }
                    row = false;
                }else {
                    for(int j = cols-1;j >= 0; j--){
                        if(col == true){
                            ans.push_back(grid[i][j]);
                            col = false;
                        }else {
                            col = true;
                        }
                    }
                    row = true;
                }
            }
    
            return ans;
        }
    };
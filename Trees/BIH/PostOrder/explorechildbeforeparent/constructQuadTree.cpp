// https://leetcode.com/problems/construct-quad-tree/?envType=problem-list-v2&envId=tree

// Time : O(n^2logn)
// Space : O(n)

 bool isSame(vector<vector<int>> &grid, int sr, int er, int sc, int ec){
        int elem = grid[sr][sc];
        for(int i = sr; i<=er; i++) {
            for(int j = sc; j<= ec; j++) {
                if(grid[i][j] != elem) {
                    return false;
                }
            }
        }
        
        return true;
    }

    Node* helper(vector<vector<int>> &grid, int rows, int cols, int startRow, int endRow, int startCol, int endCol){
        // base case 
    if(isSame(grid, startRow, endRow, startCol, endCol)){
            bool value = true;
            if(grid[startRow][startCol] == 0){
                value = false;
            }
            Node* root = new Node(value , true, NULL, NULL, NULL, NULL);
            return root;
        }
        if(startRow > endRow) {
            return NULL;
        }

    int midRow = startRow + (endRow - startRow)/2;
    int midCol = startCol + (endCol - startCol)/2;

    Node* topLeftNode = helper(grid, rows, cols, startRow, midRow, startCol, midCol);
    Node* topRightNode = helper(grid, rows, cols,  startRow, midRow, midCol+1, endCol);
    Node* bottomLeftNode = helper(grid, rows, cols, midRow+1, endRow, startCol, midCol);
    Node* bottomRightNode = helper(grid, rows, cols,  midRow+1, endRow, midCol+1, endCol);

    Node* node = new Node(true, false);
    node -> topLeft = topLeftNode;

    node -> topRight = topRightNode;
    node -> bottomLeft = bottomLeftNode;
    node -> bottomRight = bottomRightNode;

    return node;
    }


        

        
    Node* construct(vector<vector<int>> &grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        return helper(grid, rows, cols, 0, rows-1, 0, cols-1);
    }
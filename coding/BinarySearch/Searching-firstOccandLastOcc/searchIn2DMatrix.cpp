// https://leetcode.com/problems/search-a-2d-matrix/

// Time : O(log(m*n))
// Space : O(1)

 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // start from top rifght 
        // now if the elem is greater search on left side 
        // if the elem is smaller search in below rows

        int rows = matrix.size();
        int cols = matrix[0].size();

        // we will start from top right 
        int i = 0;
        int j = cols-1;

        if(rows == 0 || cols == 0){
            return false;
        }

        if(rows == 1 && cols == 1){
            if(matrix[0][0] == target){
                return true;
            }else {
                return false;
            }
        }

        // binary search 
        while(i >= 0 && i < rows && j >= 0 && j < cols){
            if(matrix[i][j] == target){
                return true;
            }else if(matrix[i][j] > target){
                j--;
            }else {
                i++;
            }
        }

        return false;
    }
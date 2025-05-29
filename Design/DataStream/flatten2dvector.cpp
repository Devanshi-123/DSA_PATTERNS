// https://leetcode.com/problems/flatten-2d-vector/

// Time : O(rows*cols)
// Space : O(rows*cols)

vector<int>iter;
    int k = 0;
    int n = 0;
    Vector2D(vector<vector<int>>& vec) {
        // to prevent heap buffer overflow problem 
        for(auto row : vec){
            for(auto val : row){
                iter.push_back(val);
            }
        }
        n = iter.size();
    }
    
    int next() {
        int elem = iter[k];
        k++;
        return elem;
    }
    
    bool hasNext() {
        if(k >= n){
            return false;
        }
        return true;
    }
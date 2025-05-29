// recursive 
// https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

int solve(vector<int> &arr, int i, int j){
        // base case 
        // think of first invalid input 
        if(i >= j){
            return 0;
        }
        
        int ans = INT_MAX;
        
        // for loop for k where it will move from i to j 
        for(int k = i; k<=j-1; k++){
            int left = solve(arr, i, k);
            int right = solve(arr, k+1, j);
            int temp = left + right + (arr[i-1]*arr[k]*arr[j]);
            
            ans = min(ans, temp);
        }
        
        return ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        // step 1 : identify i and j 
        // i : 1 (from left end)
        // j: n-1(from right end )
        
        int n = arr.size();
        
        return solve(arr, 1, n-1);
    }

// Memoization 

 int solve(vector<int> &arr, int i, int j, vector<vector<int>>&dp){
        // base case 
        // think of first invalid input 
        if(i >= j){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans = INT_MAX;
        
        // for loop for k where it will move from i to j 
        for(int k = i; k<=j-1; k++){
            dp[i][k] = solve(arr, i, k, dp);
            dp[k+1][j] = solve(arr, k+1, j, dp);
            int temp = dp[i][k] + dp[k+1][j] + (arr[i-1]*arr[k]*arr[j]);
            
            ans = min(ans, temp);
        }
        
        return ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        // step 1 : identify i and j 
        // i : 1 (from left end)
        // j: n-1(from right end )
        
        int n = arr.size();
        
        vector<vector<int>>dp(102, vector<int>(102, -1));
        
        return solve(arr, 1, n-1, dp);
    }
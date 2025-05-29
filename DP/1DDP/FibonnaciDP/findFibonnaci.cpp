// overlapping subproblem 
// optimal substructure
// choice 

// Approach 1 : Recursion

// time : O(2^n)
// space : O(n) : recursion stack

int fib(int n) {
    // recursion 
    // base case 
    if(n == 0 || n == 1){
        return n;
    }

    return fib(n-1) + fib(n-2);
}

// Approach 2 : Memoization
// time : O(n)
// space : O(n) : recursion stack + dp array

int helper(int n, vector<int>&dp){
    // base case 
    if(n == 0 || n == 1){
        return n;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    return dp[n] = helper(n-1, dp) + helper(n-2, dp);
}
int fib(int n) {
    // recursion 
    // base case 
    
    if(n == 0 || n == 1){
        return n;
    }

    vector<int>dp(n+1, -1);

    return helper(n, dp);
}

// Approach 3 : Tabulation
// time : O(n)
// space : O(n) : dp array
int helper(int n, vector<int>&dp){
    // base case 
    dp[0] = 0;
    dp[1] = 1;

    // iterative approach 
    for(int i = 2; i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}
int fib(int n) {
    // recursion 
    // base case 
    
    if(n == 0 || n == 1){
        return n;
    }

    vector<int>dp(n+1, -1);

    return helper(n, dp);
}

// Approach 4 : Space Optimization

// time : O(n)
// space : O(1) : 2 variables

int fib(int n) {
    // recursion 
    // base case 
    
    if(n == 0 || n == 1){
        return n;
    }

    int prev2 = 0;
    int prev1 = 1;

    for(int i = 2; i<=n;i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
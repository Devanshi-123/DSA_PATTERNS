// https://leetcode.com/problems/climbing-stairs/

// Time Complexity: O(2^n) : exponential
// Space Complexity: O(n) : recursion stack
// Approach 1 : Recursion

int climbStairs(int n) {
    // base case 
    if(n <= 2){
        return n;
    }

    return climbStairs(n-1) + climbStairs(n-2);
}

// Approach 2 : Memoization
// Time Complexity: O(n)
// Space Complexity: O(n) : recursion stack + dp array

int helper(int n, vector<int>&dp){
    if(n <= 2){
        return n;
    }

    // cache hit 
    if(dp[n] != -1){
        return dp[n];
    }

    return dp[n] = helper(n-1, dp) + helper(n-2, dp);
}
int climbStairs(int n) {
    // base case 
    if(n <= 2){
        return n;
    }

    vector<int>dp(n+1, -1);

    return helper(n, dp);
}

// Approach 3 : Tabulation
// Time Complexity: O(n)
// Space Complexity: O(n) : dp array

int helper(int n, vector<int>&dp){
    // iteratively 
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

     for(int i = 3; i<=n;i++){
         dp[i] = dp[i-1] + dp[i-2];
     }

     return dp[n];
 }
 int climbStairs(int n) {
     // base case 
     if(n <= 2){
         return n;
     }

     vector<int>dp(n+1, -1);

     return helper(n, dp);
 }

// Approach 4 : Space Optimization
// Time Complexity: O(n)
// Space Complexity: O(1) : 2 variables
int climbStairs(int n) {
    // base case 
    if(n <= 2){
        return n;
    }

    int prev1 = 1;
    int prev2 = 2;

    for(int i = 3; i<=n;i++){
        int curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }

    return prev2;
}


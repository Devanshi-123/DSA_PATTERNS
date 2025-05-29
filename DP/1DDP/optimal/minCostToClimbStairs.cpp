// https://leetcode.com/problems/min-cost-climbing-stairs/

// Approach 1 : Recursion 

int helper(int i, int n, vector<int>& cost, int& minCost){
    if(i >= n){
        return 0;
    }

    if(i == n - 1){
        return cost[i];
    }

    // choice 1 
    int step1 = cost[i] + helper(i + 1, n, cost, minCost);
    // choice 2 
    int step2 = cost[i] + helper(i + 2, n, cost, minCost);

    minCost = min(step1, step2);

    return minCost;
}
    int minCostClimbingStairs(vector<int>& cost) {
    // choice 1 or 2 steps 
    // optimal : min cost 

    // dp 1d 

    int n = cost.size();

    if(n == 2){
        return min(cost[0],cost[1]);
    }

    int minCost = 0;

    
    int start0 =  helper(0, n, cost, minCost);
    int start1 = helper(1, n, cost, minCost);
    return min(start0, start1);
}

// Approach 2 : Memoization
// Time : O(n)
// Space : O(n) + O(n) = O(n)

int helper(int i, int n, vector<int>& cost, vector<int>& dp){
    if(i >= n){
        return 0;
    }

    if(i == n - 1){
        return cost[i];
    }

    if(dp[i] != -1){
        return dp[i];
    }

    // choice 1 
    int step1 = cost[i] + helper(i + 1, n, cost, dp);
    // choice 2 
    int step2 = cost[i] + helper(i + 2, n, cost, dp);

    dp[i] = min(step1, step2);

    return dp[i];
}
int minCostClimbingStairs(vector<int>& cost) {
    // choice 1 or 2 steps 
    // optimal : min cost 

    // dp 1d 

    int n = cost.size();

    if(n == 2){
        return min(cost[0],cost[1]);
    }

    vector<int>dp(n + 1, -1);
    
    int start0 =  helper(0, n, cost, dp);
    int start1 = helper(1, n, cost, dp);
    return min(start0, start1);
}

// Approach 3 : Tabulation
// Time : O(n)
// Space : O(n)
int dp[1002];
int helper(vector<int>&nums, int n){
    dp[0] = 0;
    dp[1] = 0;

    for(int i=2;i<=n;i++){
        dp[i] = min(dp[i-1]+nums[i-1], dp[i-2]+nums[i-2]);
    }

    return dp[n];

}
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();

    if(n == 0 || n == 1){
        return 0;
    }

    return helper(cost, n);

}

// Approach 4 : Space Optimization
// Time : O(n)
// Space : O(1)

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();

    if(n == 0 || n == 1){
        return 0;
    }

    int prev2 = 0;
    int prev1 = 0;

    for(int i=2;i<=n;i++){
        int curr = min(prev1 + cost[i-1], prev2 + cost[i-2]);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;

}
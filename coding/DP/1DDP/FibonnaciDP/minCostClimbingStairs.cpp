// https://leetcode.com/problems/min-cost-climbing-stairs/

int helper(int i, int n, vector<int> &cost, vector<int> &dp){
        if(i >= n){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        // two choices 
        int oneStep = cost[i] + helper(i+1, n, cost, dp);
        int twoStep = cost[i] + helper(i+2, n, cost, dp);

        return dp[i] = min(oneStep, twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // cost 
        // two choices : 1 step or 2 steps 

        int n = cost.size();

        vector<int>dp(n+1, -1);

        int startWith0 = helper(0, n, cost, dp);
        int startWith1 = helper(1, n, cost, dp);

        return min(startWith0, startWith1);
    }
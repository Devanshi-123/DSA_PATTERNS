// https://leetcode.com/problems/coin-change/
// Time Complexity: O(n * amount)
// Space Complexity: O(n * amount)


int helper(int i, int n, int amount, vector<int> &coins, vector<vector<int>> &dp){
        // base case
        if(amount == 0){
            return 0;
        }

        if(i >= n){
            return INT_MAX;
        }

        // check 
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }

        // explore choices for valid cond 
        if(amount >= coins[i]){
            int take = INT_MAX;
            int res = helper(i, n, amount - coins[i], coins, dp);
            if(res != INT_MAX){
                take = 1 + res;
            }
            int nottake = helper(i+1, n, amount, coins, dp);
            return dp[i][amount] = min(take, nottake);
        }else {
            return dp[i][amount] = helper(i+1, n, amount, coins, dp);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        // coins : denominations 
        // amount : total money 
        // min numb of coins that make up the amount : -1 

        int n = coins.size();

        if(amount == 0){
            return 0;
        }

        // 2d dp 
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));

        int ans = helper(0, n, amount, coins, dp);

        if(ans == INT_MAX){
            return -1;
        }

        return ans;

    }

// Approach 2 : Tabulation

class Solution {
public:
    long long dp[13][10004];
    int helper(vector<int>&coins, int amount, int n){

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                if (j == 0) {
                    dp[i][j] = 0;
                } else if (i == 0) {
                    dp[i][j] = INT_MAX;
                }
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1] <= j){
                    dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
                } else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        if(dp[n][amount] == INT_MAX){
            return -1;
        }

        return dp[n][amount];

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        return helper(coins, amount, n);
    }
};
// Number of combinations to make a target amount with given coins

// Recursion + meoization 
// Time Complexity: O(n * amount)
// Space Complexity: O(n * amount)

  int helper(int n, int amount, vector<int> &coins, vector<vector<int>> &dp){
        // cond case 
        if(amount == 0 && n >= 0){
            return 1;
        }

        // base case 
        if(n <= 0){
            return 0;
        }

        if(dp[n][amount] != -1){
            return dp[n][amount];
        }

        // explore valid choices 
        if(coins[n-1] <= amount){
            int take = helper(n, amount - coins[n-1], coins, dp);
            int notTake = helper(n-1, amount, coins, dp);

            return dp[n][amount] = take + notTake;
        }else {
            int notTake = helper(n-1, amount, coins, dp);
            return dp[n][amount] = notTake;
        }
    }
    int change(int amount, vector<int>& coins) {
        // coins 
        // amount 

        // 
        int n = coins.size();

        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));

        return helper(n, amount, coins, dp);
    }

// Tabulation 

 int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int t[n+1][amount+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<amount+1;j++)
            {
                if(j==0)
                {
                    t[i][j]=1;
                }
                if(i==0&&j!=0)
                {
                    t[i][j]=0;
                }
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<amount+1;j++)
            {
                if(coins[i-1]<=j)
                {
                    t[i][j]=(long long)t[i-1][j]+(long long)t[i][j-coins[i-1]];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][amount];
    }
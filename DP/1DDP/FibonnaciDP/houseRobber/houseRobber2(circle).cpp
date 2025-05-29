// Houses are arranged in the form of a circle.

// https://leetcode.com/problems/house-robber-ii/

// Time Complexity: O(n)
// Space Complexity: O(n) : dp array

int helper(vector<int> &nums, int i, int n, vector<int> &dp){
        // bae case 
        if(i >= n){
            return 0;
        }

        if(i == n-1){
            return nums[i];
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int rob = nums[i] + helper(nums, i+2, n, dp);
        int notrob = helper(nums, i+1, n, dp);

        return dp[i] = max(rob, notrob);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 0){
            return 0;
        }

        if(n == 1){
            return nums[0];
        }

        if(n == 2){
            return max(nums[0], nums[1]);
        }

        vector<int>dp(n+1, -1);

        int considerFirst = helper(nums, 0, n-1, dp);
        for(int i = 0; i<n; i++){
            dp[i] = -1;
        }
        int notConsiderFirst = helper(nums, 1, n, dp);

        return max(considerFirst, notConsiderFirst);
    }
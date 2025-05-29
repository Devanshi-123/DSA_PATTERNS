// https://leetcode.com/problems/house-robber/

int helper(vector<int> &nums, int i, int n){
        // base case 
        if(i >= n){
            return 0;
        }

        // if only 1 house 
        if(i == n-1){
            return nums[i];
        }

        // explore choices 
        // since if we rob a house we cannot rob the next adjacent house 
        int rob = nums[i] + helper(nums, i+2, n);
        int notRob = helper(nums, i+1, n);

        return max(rob, notRob);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        

        return helper(nums, 0, n);
    }

// Approach 2 : Memoization

int helper(vector<int> &nums, int i, int n, vector<int> &dp){
        // base case 
        if(i >= n){
            return 0;
        }

        // if only 1 house 
        if(i == n-1){
            return nums[i];
        }

        if(dp[i] != -1){
            return dp[i];
        }

        // explore choices 
        // since if we rob a house we cannot rob the next adjacent house 
        int rob = nums[i] + helper(nums, i+2, n, dp);
        int notRob = helper(nums, i+1, n, dp);

        return dp[i] = max(rob, notRob);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n+1, -1);

        return helper(nums, 0, n, dp);
    }
// https://leetcode.com/problems/longest-increasing-subsequence/

// Approach 1: Recursion 
// Time O(2^n)
// Space O(n)

int helper(vector<int> &nums, int n, int idx, int prev){
        // base case 
        if(idx >= n){
            return 0;
        }

        // explore choices 
        int take = 0;
        if(nums[idx] > prev){
            take = 1 + helper(nums, n, idx+1, nums[idx]);
        }

        int skip = helper(nums, n, idx+1, prev);

        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        if(n == 0 || n == 1){
            return n;
        }

        int prev = INT_MIN; 

        return helper(nums, n, 0, prev);
    }

// Memoizaton 

// Time O(n^2)
// Space O(n^2) + O(n) for recursion stack

int helper(vector<int> &nums, int n, int idx, int prevIdx, vector<vector<int>> &dp){
        // base case 
        if(idx >= n){
            return 0;
        }

        if(dp[idx][prevIdx+1] != -1){
            return dp[idx][prevIdx+1];
        }

        // explore choices 
        int take = 0;
        if(prevIdx == -1 || nums[idx] > nums[prevIdx]){
            take = 1 + helper(nums, n, idx+1, idx, dp);
        }

        int skip = helper(nums, n, idx+1, prevIdx, dp);

        return dp[idx][prevIdx+1] = max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        if(n == 0 || n == 1){
            return n;
        }

        int prev = INT_MIN; 

        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        return helper(nums, n, 0, -1, dp);
    }

// Tabulation

// Time O(n^2)
// Space O(n)

 int helper(vector<int> &nums, int n){
        // base case 
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        for(int idx = n-1; idx >= 0; idx--){
            for(int prevIdx = idx-1; prevIdx >= -1; prevIdx--){
                int take = 0;
                if(prevIdx == -1 || nums[idx] > nums[prevIdx]){
                    take = 1 + dp[idx+1][idx+1];
                }
                int skip = dp[idx+1][prevIdx+1];
                 dp[idx][prevIdx + 1] = max(take, skip);
            }
        }
        return dp[0][0];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        if(n == 0 || n == 1){
            return n;
        }

        return helper(nums, n);
    }

// The dp array will be storing the length of the longest increasing subsequence that ends at index i.

// time : O(n^2)
// space : O(n)

  int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n+1, 1);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j] && dp[i] < dp[j] +1){
                    dp[i] = dp[j] +1;
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
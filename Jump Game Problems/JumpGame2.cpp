// https://leetcode.com/problems/jump-game-ii/

// // Time : O(n)
// // Space : O(1)
// Approach 1 : Greedy 

class Solution {
    public:
    // we will jump only when it is atmost necessary 
    // i.e. we have reached the end of the current window and
    //  cannot move forward so need to have a next window where the farthest will tell us the end of that window 
    
    // hm tb tk jump nhi krenge jb tk window m chal skte hain and 
    // meanwhile will find out what is the maxm index that we can jump to from this window and will consider that index as the end of next window while jumping
        int jump(vector<int>& nums) {
             int n = nums.size();
    
            if(n == 1){
                return 0;
            }
    
            int farthestIdx = 0;
            int count = 0;
            int currEnd = 0;
    
            for(int i = 0; i<n;i++){
                farthestIdx = max(farthestIdx, i+nums[i]);
    
                // if i have reached the ednd of this window 
                if(i == currEnd){
                    count++;
                    // farthest is the maxm index we can go in the coming window 
                    currEnd = farthestIdx;
    
                    if(currEnd >= n-1){
                        return count;
                    }
                }
            }
    
            return count;
        }
    };


// Approach 2 : DP + Recursion 

class Solution {
    private:
        // min jumps to reach end of nums 
        int helper(int i, vector<int> &nums, int n){
            // base case 
            if(i >= n-1){
                return 0;
            }
    
            if(nums[i] == 0){
                return INT_MAX;
            }
    
            int minJumps = INT_MAX;
    
            // explore choices 
    
            for(int j = 1; j <= nums[i] ; j++){
                int nextIdx = i+j;
                // number of jumps to reach end from nextidx 
                int jumps = helper(nextIdx, nums, n);
                if(jumps != INT_MAX){
                    minJumps = min(minJumps, 1+jumps);
                }
            }
    
            return minJumps;
        }
    public:
        int jump(vector<int>& nums) {
            int n = nums.size();
    
            if(n <= 1){
                return 0;
            }
    
            return helper(0, nums, n);
        }
    };

// Dp+ memoization 

class Solution {
    private:
        // min jumps to reach end of nums 
        int helper(int i, vector<int> &nums, int n, vector<int>&dp){
            // base case 
            if(i >= n-1){
                return 0;
            }
    
            if(nums[i] == 0){
                return INT_MAX;
            }
    
            if(dp[i] != INT_MAX){
                return dp[i];
            }
    
            // explore choices 
    
            for(int j = 1; j <= nums[i] ; j++){
                int nextIdx = i+j;
                // number of jumps to reach end from nextidx 
                int jumps = helper(nextIdx, nums, n, dp);
                if(jumps != INT_MAX){
                    dp[i] = min(dp[i], 1+jumps);
                }
            }
    
            return dp[i];
        }
    public:
        int jump(vector<int>& nums) {
            int n = nums.size();
    
            if(n <= 1){
                return 0;
            }
    
            vector<int>dp(n+1, INT_MAX);
    
            return helper(0, nums, n, dp);
        }
    };

// Approach 3 : DP + Tabulation

class Solution {
    private:
        // min jumps to reach end of nums 
        int helper(vector<int> &nums, int n, vector<int>&dp){
            // base case 
            dp[0] = 0;
    
            for(int i = 1; i<n;i++){
            // explore choices 
    
                for(int j = 0; j<=i; j++){
                    if(j + nums[j] >= i && dp[j] != INT_MAX){
                        dp[i] = min(dp[i], 1+dp[j]);
                    }
                }
            }
    
            return dp[n-1];
        }
    public:
        int jump(vector<int>& nums) {
            int n = nums.size();
    
            if(n <= 1){
                return 0;
            }
    
            vector<int>dp(n+1, INT_MAX);
    
            return helper(nums, n, dp);
        }
    };
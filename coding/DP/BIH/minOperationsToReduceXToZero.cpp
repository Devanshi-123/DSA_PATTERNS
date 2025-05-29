// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

// Approach 1: Recursion
// O(2^n) time and O(n) space

class Solution {
    private:
        int helper(int left, int right,vector<int> &nums, int x){
            // base case 
            // cc 
            if(x == 0){
                return 0;
            }
    
            // bc 
            if(left > right || x < 0){
                return INT_MAX;
            }
    
            //induction 
            int leftCount = helper(left+1, right, nums, x-nums[left]);
            int rightCount = helper(left, right-1, nums, x-nums[right]);
    
            // hypothesis
            int minCount = min(leftCount, rightCount);
    
            if(minCount == INT_MAX){
                return INT_MAX;
            }
    
            return 1+minCount;
            
        }
    public:
        int minOperations(vector<int>& nums, int x) {
            // dp 
            // choice to select first or last 
    
            int n = nums.size();
    
            if(n == 1){
                if(nums[0] == x){
                    return 1;
                }else{
                    return -1;
                }
            }
    
            int res =  helper(0, n-1, nums, x);
            if(res == INT_MAX){
                return -1;
            }
    
            return res;
    
        }
    };

// Approach 2: Memoization

// O(n^2) time and O(n^2) space
// O(n^2) space for dp
// O(n^2) space for recursion stack

class Solution {
    private:
    // since two variables are changing so 2d dp 
        int helper(int left, int right,vector<int> &nums, int x, vector<vector<int>>&dp){
            // base case 
            // cc 
            if(x == 0){
                return 0;
            }
    
            // bc 
            if(left > right || x < 0){
                return INT_MAX;
            }
    
            if(dp[left][right] != -1){
                return dp[left][right];
            }
    
            //induction 
            int leftCount = helper(left+1, right, nums, x-nums[left], dp);
            int rightCount = helper(left, right-1, nums, x-nums[right], dp);
    
            // hypothesis
            int minCount = min(leftCount, rightCount);
    
            if(minCount == INT_MAX){
                return dp[left][right] = INT_MAX;
            }
    
            return dp[left][right] = 1+minCount;
            
        }
    public:
        int minOperations(vector<int>& nums, int x) {
            // dp 
            // choice to select first or last 
    
            int n = nums.size();
    
            if(n == 1){
                if(nums[0] == x){
                    return 1;
                }else{
                    return -1;
                }
            }
    
            vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
    
            int res =  helper(0, n-1, nums, x, dp);
            if(res == INT_MAX){
                return -1;
            }
    
            return res;
    
        }
    };
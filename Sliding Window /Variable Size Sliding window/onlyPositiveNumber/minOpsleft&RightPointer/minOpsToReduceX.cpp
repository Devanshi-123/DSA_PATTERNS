// Mostly in optimoisation problem we use sliding window or dp or greedy 


// Greedy 
// Here i tried to take maxm of two pointers i.e. left and right but wrong 

class Solution {
    public:
        int minOperations(vector<int>& nums, int x) {
            int n = nums.size();
    
            if(n == 1){
                if(nums[0] == x){
                    return 1;
                }else{
                    return 0;
                }
            }
    
            int left = 0;
            int right = n-1;
            int count = 0;
    
            while(left <= right && nums.size() > 0 && x != 0){
                cout << "nl" << nums[left] << endl;
                cout << "nr" << nums[right] << endl;
                if(nums[left] <= x && nums[right] <= x){
                    if(nums[left] >= nums[right]){
                        x -= nums[left];
                        nums.erase(nums.begin());
                    }else {
                        x -= nums[right];
                        nums.erase(nums.begin()+n);
                    }
                    count++;
                    left = 0;
                    right = nums.size()-1;
                    if(x == 0){
                        return count;
                    }
                }else if(nums[left] <= x){
                    x -= nums[left];
                    nums.erase(nums.begin());
                    count++;
                    left = 0;
                    right = nums.size()-1;
                    if(x == 0){
                        return count;
                    }
                }else if(nums[right] <= x){
                    x -= nums[right];
                    nums.erase(nums.begin()+n);
                    count++;
                    left = 0;
                    right = nums.size()-1;
                    if(x == 0){
                        return count;
                    }
                }else{
                    return -1;
                }
            }
            return count;
        }
    };

// DP 
// It worked but due to constraints of leetcode it is not optimal so tle 

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

// Sliding window

class Solution {
    private:
        int longestSubArrLen(vector<int> &nums,int n,int totalSum){
            int i = 0;
            int j = 0;
    
            int sum = 0;
            int maxLen = 0;
    
            while(j < n){
                sum += nums[j];
    
                // invalid 
                while(sum > totalSum && i<=j){
                    sum -= nums[i];
                    i++;
                }
    
                // valid 
                if(sum == totalSum){
                    maxLen = max(maxLen, j-i+1);
                }
    
                j++;
            }
    
            return maxLen;
        }
    public:
        int minOperations(vector<int> &nums, int x) {
            // longest subarray with sum : totalSum -x then the sum of remaining elements on the sides will be x and the ops req to delete them will be len - len of longest subarray 
    
            int n = nums.size();
            if(n == 1){
                if(nums[0] != x){
                    return -1;
                }else {
                    return 1;
                }
            }
    
            long long totalSum = 0;
            for(int i = 0; i<n;i++){
                totalSum += nums[i];
            }
    
            if(totalSum == x){
                return n;
            }
    
            int maxlen = longestSubArrLen(nums, n, totalSum-x);
            if(maxlen == 0){
                return -1;
            }
    
            return n - maxlen;
        }
    };
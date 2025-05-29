// https://leetcode.com/problems/longest-increasing-subsequence-ii/

// Time : 0(n^2)

 int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>dp(n+1, 1);

        for(int i = 1; i<n;i++){
            for(int j = 0; j<i;j++){
                if(nums[i] > nums[j] && (nums[i] - nums[j] <= k) && dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
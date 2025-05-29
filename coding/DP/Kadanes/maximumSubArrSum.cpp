// https://leetcode.com/problems/maximum-subarray/


int maxSubArray(vector<int>& nums) {
        // largest sum subarray : sum 
        // kadane's algo 

        int sum = 0;

        int maxSum = INT_MIN;
        int n = nums.size();
        int i = 0;

        while(i < n){
            sum += nums[i];

            maxSum = max(maxSum, sum);

            if(sum < 0){
                maxSum = max(maxSum, sum);
                sum = 0;
            }
            i++;
        }

        return maxSum;
        
    }
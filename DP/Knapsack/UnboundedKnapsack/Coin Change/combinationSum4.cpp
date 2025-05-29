// https://leetcode.com/problems/combination-sum-iv/submissions/482671395/

class Solution {
public:
    int helper(vector<int>nums,int target,vector<int>&dp)
    {
        if(dp[target]!=-1)
        {
            return dp[target];
        }
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            if(target>=nums[i])
            {
                res += helper(nums,target-nums[i],dp);
            }
        }
        dp[target] = res;
        return res;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        dp[0] = 1;
        return helper(nums,target,dp);
    }
};
// https://leetcode.com/problems/single-element-in-a-sorted-array/

// xor of same elem is 0 and diff is 1 

 int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        for(int i=0;i<n;i++)
        {
            ans = ans^nums[i];
        }
        return ans;
    }
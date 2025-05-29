// https://leetcode.com/problems/binary-subarrays-with-sum/

// count of subarrays with sum == goal = count of subarrays with sum <= goal - count of subarrays with sum <= goal - 1

// Time : O(n)
// Space : O(1)

int helper(vector<int>& nums, int goal){
    if(goal < 0){
        return 0;
    }
    int n = nums.size();
    int count = 0;
    int i = 0;
    int j = 0;

    int sum = 0;

    while(j < n){
        sum += nums[j];

        while(sum > goal){
            sum -= nums[i];
            i++;
        }

        if(sum <= goal){
            count += j-i+1;
        }

        j++;
    }

    return count;
}
int numSubarraysWithSum(vector<int>& nums, int goal) {
    return helper(nums, goal) -  helper(nums, goal-1);
}
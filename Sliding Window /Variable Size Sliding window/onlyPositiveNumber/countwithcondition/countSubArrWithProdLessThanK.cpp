//https://leetcode.com/problems/subarray-product-less-than-k/description/

// Time : O(n)
// Space : O(1)

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    // variable sized sliding window 
    // number of subarrays ending at j will be j-i+1;

    int i = 0;
    int j = 0;

    int n = nums.size();

    if(n == 1 && nums[0] >= k){
        return 0;
    }

    int prod = 1;
    int count = 0;

    while(j < n){
        // perf calc 
        prod *= nums[j];

        // if not valid 
        while(prod >= k && i <= j){
            prod /= nums[i];
            i++;
        }

        count += j-i+1;
        j++;
    }

    return count;
}
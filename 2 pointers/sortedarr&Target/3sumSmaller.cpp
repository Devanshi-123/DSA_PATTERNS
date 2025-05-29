// https://leetcode.com/problems/3sum-smaller/description/

// Brute force : O(n3)

// Time : O(n2logn)
// Space : O(1)
// Approach : 1. Sort the array in ascending order.
// 2. Initialize a variable count to 0.
// 3. Iterate through the array with an index i from 0 to n-2.
// 4. For each index i, set a new target as target - nums[i].
// 5. Initialize two pointers, left and right, at the beginning and end of the subarray nums[i+1:n] respectively.
// 6. While left is less than right, calculate the sum of the elements at the two pointers.
// 7. If the sum is less than the target, increment count by (right - left) and move the left pointer to the right.
// 8. If the sum is greater than or equal to the target, move the right pointer to the left.
// 9. Return the count as the final result.

int twoSum(vector<int>&nums, int target, int start, int end){
    int count = 0;

    while(start < end){
        if(nums[start] + nums[end] < target){
            count += end-start;
            start++;
        }else {
            end--;
        }   
    }
    return count;
}
int threeSumSmaller(vector<int>& nums, int target) {
    // n 
    // nums 
    // target 
    int n = nums.size();

    sort(nums.begin(), nums.end());

    if(n < 3){
        return 0;
    }

    int numDuplets = 0;

    for(int i = 0; i<n-2; i++){
        int subTarget = target - nums[i];
        numDuplets += twoSum(nums, subTarget, i+1, n-1);
    }

    return numDuplets;
}
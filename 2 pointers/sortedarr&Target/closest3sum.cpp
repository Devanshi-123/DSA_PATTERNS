// https://leetcode.com/problems/3sum-closest/description/

// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
// Return the sum of the three integers.
// You may assume that each input would have exactly one solution.
// Constraints:
// 3 <= nums.length <= 1000
// -1000 <= nums[i] <= 1000
// -10^4 <= target <= 10^4
// Follow up: Can you solve it in O(n^2) time complexity?


// Time : O(n^2)
// Space: O(1)

pair<int,int> twoSum(vector<int>&nums, int target, int left, int right){
    pair<int,int>p;
    p.first = INT_MAX;
    p.second = 0;

    while(left < right){
        int sum = nums[left] + nums[right];

        if(sum == target){
            p.first = 0;
            p.second = sum;
            return p;
        }else if(sum < target){
            int diff = abs(target - sum);
            if(diff < p.first){
                p.first = diff;
                p.second = sum;
            }
            left++;
        }else {
            int diff = abs(target - sum);
            if(diff < p.first){
                p.first = diff;
                p.second = sum;
            }
            right--;
        }
    }

    return p;
}
int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    // integers with closest sum 

    sort(nums.begin(), nums.end());
    int diff = INT_MAX;
    int closestSum = 0;

    for(int i = 0; i<n-2; i++){
        int newTarget = target - nums[i];

        // this will return a sum and a diff 
        pair<int,int>p = twoSum(nums, newTarget, i+1, n-1);
        if(p.first < diff){
            diff = p.first;
            closestSum = p.second + nums[i];
        }
    }

    return closestSum;

}
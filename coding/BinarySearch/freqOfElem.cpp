// https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/submissions/1604412805/

// Time : O(nlogn)
// Space : O(1)

bool isMajorityElement(vector<int>& nums, int target) {
    // when the array is sorted we can even find freq without using hash map 

    int n = nums.size();

    int maxFreq = 0;

    for(int i = 0; i< n;i++){
        int freq = upper_bound(nums.begin(), nums.end(), nums[i]) - lower_bound(nums.begin(), nums.end(), nums[i]);
        if(freq > n/2 && nums[i] == target){
            return true;
        }
    }

    return false;
}
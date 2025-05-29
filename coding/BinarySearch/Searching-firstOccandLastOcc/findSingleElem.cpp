//  https://leetcode.com/problems/single-element-in-a-sorted-array/

// // Time : O(logn)
// // Space : O(1)



int singleNonDuplicate(vector<int>& nums) {
        // sorted 
        // integres 
        // freq elem : 2 except 1 elem : freq 1

        int n = nums.size();

        if(n == 1){
            return nums[0];
        }

        int start = 0;
        int end = n-1;

        while(start <= end){
            int mid = start + (end-start)/2;

            if((mid == 0 && nums[mid] != nums[mid+1]) || (mid == n-1 && nums[mid] != nums[mid-1]) || (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])){
                return nums[mid];
            }else if((nums[mid] == nums[mid-1] && (mid%2 == 0)) || (nums[mid] == nums[mid+1] && (mid%2 != 0))){
                end = mid-1;
            }else {
                start = mid+1;
            }
        }
        return -1;
    }
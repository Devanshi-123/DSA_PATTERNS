// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/1642024665/

int findMin(vector<int>& nums) {
        int n = nums.size();

        int start = 0;
        int end = n-1;

        // we can find the elem in unsorted part
        while(start <= end){
            int mid = start + (end-start)/2;

            if((mid == 0 || nums[mid] < nums[mid-1]) && (mid == n-1 || nums[mid] < nums[mid+1])){
                return nums[mid];
            }else if(nums[mid] < nums[end]){
                end = mid-1;
            }else {
                start = mid+1;
            }
        }

        return -1;
    }
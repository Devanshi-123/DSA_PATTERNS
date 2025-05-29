// https://leetcode.com/problems/find-peak-element/

    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        int start = 0;
        int end = n-1;

        while(start <= end){
            int mid = start + (end-start)/2;

            if((mid == 0 || nums[mid] > nums[mid-1]) && (mid == n-1 || nums[mid] > nums[mid+1])){
                return mid;
            }else if(mid < n-1 && nums[mid] < nums[mid+1]){
                start = mid+1;
            }else {
                end = mid - 1;
            }
        }

        return -1;
    }
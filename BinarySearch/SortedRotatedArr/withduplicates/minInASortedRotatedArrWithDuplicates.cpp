// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/?envType=problem-list-v2&envId=binary-search

    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;

        if(n == 1){
            return nums[0];
        }

        // there is a higher probability of finding the element in the unsorted part of array 

        while(start < end){
            int mid = start + (end-start)/2;

            if(nums[mid] > nums[end]){                            
                start = mid+1;
            }else if(nums[mid] < nums[end]){
                end = mid;
            }else {
                end--;
            }
        }
        // since now start == end so nwe just have one elem as we have removed all the greater elem 
        return nums[start];
    }
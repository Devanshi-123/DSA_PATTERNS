// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

// Time : O(logn)
// Space : O(1)


bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int start = 0;
        int end = n-1;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(nums[mid] == target){
                return true;
            }

            // remove duplicates 
            // since we dont know where to move so shrink 
            if(nums[start] == nums[mid] && nums[mid] == nums[end]){
                start++;
                end--;
                if(start > end){
                    break;
                }
            }
            // first half is sorted 
            else if(nums[start] <= nums[mid]){
                // it means target lies in first half then search for it or search in the unsorted part
                if(target >= nums[start] && target < nums[mid]){
                    end = mid-1;
                }else {
                    start = mid+1;
                }
            }else{
                if(target > nums[mid] && target <= nums[end]){
                    start = mid+1;
                }else {
                    end = mid-1;
                }
            }
        }

        return false;
    }
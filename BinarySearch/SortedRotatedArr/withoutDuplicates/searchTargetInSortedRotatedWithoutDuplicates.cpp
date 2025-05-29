// https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/1405518886/

class Solution {
public:
    int peakIdx(vector<int>&nums){
        int n = nums.size();

        int start = 0;
        int end = n-1;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(nums[start] < nums[end]){
                return end;
            }

            if((mid == 0 || nums[mid] > nums[mid-1]) && (mid == n-1 || nums[mid] > nums[mid+1])){
                return mid;
            } else if(nums[start] <= nums[mid]){
                start = mid+1;
            } else{
                end = mid-1;
            }
        }

        return -1;
    }
    int binarySearch(vector<int>&nums, int start, int end, int elem){
        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid] == elem){
                return mid;
            } else if(nums[mid] < elem){
                start = mid+1;
            } else {
                end = mid-1;
            }
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        if(n == 0){
            return -1;
        }

        if(n == 1 && nums[0] != target){
            return -1;
        }

        // idx of peak element 
        int idx = peakIdx(nums);
        int first = binarySearch(nums, 0, idx, target);
        int second = binarySearch(nums, idx+1, n-1, target);

        if(first == -1 && second == -1){
            return -1;
        } else if(first != -1){
            return first;
        } else {
            return second;
        }
    }
};
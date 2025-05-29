// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/1642134655/


int firstOccurence(vector<int> &nums, int target, int start, int end){
        int ans = -1;
        while(start <= end){
            int mid = start + (end-start)/2;

            if(nums[mid] == target){
                ans = mid;
                end = mid-1;
            }else if(nums[mid] < target){
                start = mid+1;
            }else {
                end = mid-1;
            }
        }
        return ans;
    }
    int lastOccurence(vector<int> &nums, int target, int start, int end){
        int ans = -1;
        while(start <= end){
            int mid = start + (end-start)/2;

            if(nums[mid] == target){
                ans = mid;
                start = mid+1;
            }else if(nums[mid] < target){
                start = mid+1;
            }else {
                end = mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>occ;

        int n = nums.size();

        int firstOcc = firstOccurence(nums, target, 0, n-1);
        int lastOcc = lastOccurence(nums, target, 0, n-1);

        occ.push_back(firstOcc);
        occ.push_back(lastOcc);

        return occ;
    }
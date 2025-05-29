// https://leetcode.com/problems/find-in-mountain-array/submissions/1642179516/

int findPeakIdx(MountainArray &mountainArr, int start, int end, int n){
        while(start <= end){
            int mid = start + (end - start)/2;

            int val = mountainArr.get(mid);
            int leftVal = mid > 0 ? mountainArr.get(mid-1) : INT_MAX;
            int rightVal = mid < n-1 ? mountainArr.get(mid+1) : INT_MAX;

            if((mid == 0 || val > leftVal) && (mid == n-1 || val > rightVal)){
                return mid;
            }else if(mid < n-1 && val < rightVal){
                start = mid+1;
            }else {
                end = mid-1;
            }
        }
        return -1;
    }
    // bs when arr is sorted in asc orderr
    int firstHalf(MountainArray &mountainArr,int target, int start, int end) {
        int ans = -1;
        while(start <= end){
            int mid = start + (end-start)/2;

            if(mountainArr.get(mid) == target){
                ans = mid;
                end = mid-1;
            }else if(mountainArr.get(mid) < target){
                start = mid+1;
            }else {
                end = mid-1;
            }
        }
        return ans;
    }
    // bs when arr is sorted in desc order 
    int secondHalf(MountainArray &mountainArr,int target,int start, int end) {
        int ans = -1;
        while(start <= end){
            int mid = start + (end-start)/2;

            if(mountainArr.get(mid) == target){
                ans = mid;
                end = mid-1;
            }else if(mountainArr.get(mid) < target){
                end = mid-1;
            }else {
                start = mid+1;
            }
        }
        return ans;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // n >= 3
        // min index : where arr[idx] = target

        int n = mountainArr.length();

        int start = 0;
        int end = n-1;

        // peak elem idx 

        int peakidx = findPeakIdx(mountainArr, 0, n-1, n);

        int firstHalfIdx = firstHalf(mountainArr, target, 0, peakidx);
        int secondHalfIdx = secondHalf(mountainArr, target, peakidx+1, n-1);

        if(firstHalfIdx == -1 && secondHalfIdx == -1){
            return -1;
        }else if(firstHalfIdx != -1 ){
            return firstHalfIdx;
        }else {
            return secondHalfIdx;
        }

        return -1;
    }
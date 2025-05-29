// http://leetcode.com/problems/peak-index-in-a-mountain-array/submissions/1642074803/

int peakIndexInMountainArray(vector<int>& arr) {
        // arr : n 
        // first val increase then decrease

        int n = arr.size();

        int start = 0;
        int end = n-1;

        while(start <= end){
            int mid = start + (end-start)/2;

            if((mid == 0 || arr[mid] > arr[mid-1]) && (mid == n-1 || arr[mid] > arr[mid+1])){
                return mid;
            }else if(mid < n-1 && arr[mid] < arr[mid+1]){
                start = mid+1;
            }else {
                end = mid - 1;
            }
        }

        return -1;
    }